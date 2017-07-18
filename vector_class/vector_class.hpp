//--------------------------------------
//! \file vector_class.hpp
//! \brief Contains definitions of vector class functions
//! \author theSonOfMan, 2017
//--------------------------------------

#define DEBUG
//#define LOG_VERBOSITY

// FIXME: я не совсем это имел ввиду. У тебя же есть файл my_dump.h. В этом файле есть ASSERT_OK, который выводит какую-то
// информацию куда-то. Логично там же завести макрос LOG_PRINT, который ничего не проверяет, а просто печатает на экран какую-то информацию.
// А потом уже ты юудешь писать в коде что-то типа: LOG_PRINT("Я родился в участве памяти"). Если хочешь, можешь это сделать
// строковой константой. Но не надо специально под это делать свой макрос.
// Что касается LOG_VERBOSITY, я имел ввиду несколько уровней важности: типа ERROR, WARNING, DEBUG, INFO, VERBOS. ПРи каждом вызове
// LOG_PRINT можно указывать уровень важности. А выводиться будут только сообщения с важностью больше, чем важность, лежащаяя
// в константе LOG_VERBOSITY.

// FIXME: опасный макрос. Сразу по нескольким причинам:
// 1) Представь себе код LOG_PRINT(a += b), где a и b - это какие-то строки. В итоге b прибавиться к а 3 раза.
// 2) Представь себе код if(a) LOG_PRINT(...)
//                       f()
// Если не DEBUG, то f() будет вызвана только при условии а.
#ifdef DEBUG
#ifdef LOG_VERBOSITY
#define LOG_PRINT(INFO, VAR) \
    if (INFO == "BIRTH")\
        {\
            std::cout<<"Я родился в участке памяти "<<VAR<<std::endl;\
            getchar();\
        }\
    if (INFO == "BIRTH")\ 
        {\
            std::cout<<"Я умер в участке памяти "<<VAR<<std::endl;\
            getchar();\
        }\
    if (INFO == "NEW")\
        {\
            std::cout<<"я new, я выделил память здесь: "<<VAR<<std::endl;\
            getchar();\
        }
#else
#define LOG_PRINT(INFO, VAR)
#endif
#else
#define LOG_PRINT(INFO, VAR)
#endif

template <typename T>
Vector<T>::Vector(): size_(0){
    data_ = new value_type[size_];
    ASSERT_OK(data_ != NULL)
    LOG_PRINT("BIRTH",this);
}

template <typename T>
Vector<T>::Vector(size_t vector_size): size_(vector_size){
    data_ = new value_type[size_];
    ASSERT_OK(data_ != NULL)
    for (int i=0; i<size_; i++) // FIXME: size_ имеет тип size_t и вмещает в себя числа <= 2^64. int же только до 2^31, т.е. всего миллион и его может не хватить.
        data_[i]=0; // FIXME: а еще не факт, что у твоего T есть какой-то ноль. Лучше сделать = T(), что вызовет либо конструктор по
    // умолчению, либо инициализатор для базовых типов.
    LOG_PRINT("BIRTH", this);
}

template <typename T>
Vector<T>::Vector(const Vector<T> &that):
        size_ (that.size_)
{
    data_ = new value_type[that.size_];
    ASSERT_OK(data_ != NULL)
    std::copy(that.data_, that.data_ + that.size_, data_);
    ASSERT_OK(data_ != NULL)
    LOG_PRINT("BIRTH", this);
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> init):
        size_(init.size())
{
    data_ = new value_type[init.size()];
    std::copy(init.begin(), init.end(), data_);
    ASSERT_OK(data_ != NULL)
    LOG_PRINT("BIRTH", this);
}

template <typename T>
Vector<T>::Vector(Vector<T>&& that):
        size_(that.size_),
        data_(that.data_)
{
    ASSERT_OK(data_ != NULL)
    that.size_ = 0;
    that.data_ = nullptr;
    LOG_PRINT("BIRTH", this);
}

template <typename T>
Vector<T>::~Vector() {
    ASSERT_OK(data_ != NULL)
    delete[] data_;
    LOG_PRINT("DEATH", this);
}

template <typename T>
size_t Vector<T>::size() const{
    return size_;
}

template <typename T>
typename Vector<T>::value_type* Vector<T>::data_pointer() const{
    ASSERT_OK(data_ != nullptr)
    return data_;
}

template <typename T>
void Vector<T>::print_data() const{
    ASSERT_OK(data_ != NULL)
    std::cout<<"You want to print the data of a Vector."<<endl;
    std::cout<<"Type 'file' to print in file"<<endl;
    std::cout<<"Type anything else to print in console"<<endl;
    string user_response;
    std::cin>>user_response;
    if (user_response == "file"){
        std::string path = print_data_filename();
        ofstream fout(path);
        for (int iter = 0; iter < size_; iter++)
            fout << iter << ": " << data_[iter] << std::endl;
        cout<<"data was put in "<<path<<std::endl;
        fout.close();
    } else {
        for (int iter = 0; iter < size_; iter++)
            std::cout << iter<<' '<<data_[iter] << std::endl;
        std::cout << std::endl;
    }
}

template <typename T>
const typename Vector<T>::value_type& Vector<T>::operator [] (size_t index) const{
    ASSERT_OK(index < size_)
    ASSERT_OK(data_ != NULL)
    return data_[index];
}

template <typename T>
typename Vector<T>::value_type& Vector<T>::operator[] (size_t index){
    ASSERT_OK(index < size_)
    ASSERT_OK(data_ != NULL)
    return data_[index];
}

template <typename T>
void Vector<T>::swap(Vector<T> &that) {

    size_t temp_size = size_;
    size_ = that.size_;
    that.size_ = temp_size;

    value_type* temp_data = data_;
    data_ = that.data_;
    that.data_ = temp_data;

}

template <typename T>
const Vector<T>& Vector<T>::operator = (const Vector<T>&that) {
    if (&that == this) return *this;
    this->~Vector();
    new (this) Vector(that);
    LOG_PRINT("BIRTH", this);
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> && that) {
    delete [] data_;
    data_ = that.data_;
    size_ = that.size_;
    that.data_ = nullptr;
    that.size_ = 0;
    return *this;
}

template <typename T>
void* Vector<T>::operator new (size_t size, void* where_to_create) {
    LOG_PRINT("NEW", where_to_create);
    return where_to_create;
}

template <typename T>
std::string Vector<T>::dump() const{
    ostringstream out_string;
    out_string<<"size: "<<size_<<endl;
    out_string<<"data pointer: "<<data_<<endl;
    if (data_!=NULL && size_!=0) {
        out_string<<"data:"<<endl;
        for (int iter=0; iter < size_; iter++)
            out_string<<iter<<':'<<data_[iter]<<endl;
    }
    return out_string.str();
}

//template <typename T>
//const std::string Vector<T>::dump() const{
//    ostringstream out_string;
//    out_string<<"size: "<<size_<<endl;
//    out_string<<"data pointer: "<<data_<<endl;
//    if (data_!=NULL && size_!=0) {
//        out_string<<"data:"<<endl;
//        for (int iter=0; iter < size_; iter++)
//            out_string<<iter<<':'<<data_[iter]<<endl;
//    }
//    return out_string.str();
//}

// FIXME: а резве эта функция не объявлена в my_dump?
template <typename T>
std::string Vector<T>::print_data_filename() const{
    ostringstream file_path;
    file_path<<"../data";
    file_path<<time(NULL)<<".txt";
    return file_path.str();
}
