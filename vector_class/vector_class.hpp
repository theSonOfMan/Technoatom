//--------------------------------------
//! \file vector_class.hpp
//! \brief Contains definitions of vector class functions
//! \author theSonOfMan, 2017
//--------------------------------------

template <typename T>
Vector<T>::Vector(): size_(0){
    data_ = new value_type[size_];
    ASSERT_OK(data_ != NULL)
    LOG_INFO("VECTOR CREATED");
}

template <typename T>
Vector<T>::Vector(size_t vector_size): size_(vector_size){
    data_ = new value_type[size_];
    ASSERT_OK(data_ != NULL)
    for (int i=0; i<size_; i++)
        data_[i]=0;
    LOG_INFO("VECTOR CREATED");
}

template <typename T>
Vector<T>::Vector(const Vector<T> &that):
        size_ (that.size_)
{
    data_ = new value_type[that.size_];
    ASSERT_OK(data_ != NULL)
    std::copy(that.data_, that.data_ + that.size_, data_);
    ASSERT_OK(data_ != NULL)
    LOG_INFO("VECTOR COPIED");
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> init):
        size_(init.size())
{
    data_ = new value_type[init.size()];
    std::copy(init.begin(), init.end(), data_);
    ASSERT_OK(data_ != NULL)
    LOG_INFO("VECTOR CREATED");
}

template <typename T>
Vector<T>::Vector(Vector<T>&& that):
        size_(that.size_),
        data_(that.data_)
{
    ASSERT_OK(data_ != NULL)
    that.size_ = 0;
    that.data_ = nullptr;
    LOG_INFO("VECTOR MOVED");
}

template <typename T>
Vector<T>::~Vector() {
    ASSERT_OK(data_ != NULL)
    delete[] data_;
    LOG_INFO("VECTOR DESTROYED");
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
    std::cout<<"You want to print the data of a Vector."<<std::endl;
    std::cout<<"Type 'file' to print in file"<<std::endl;
    std::cout<<"Type anything else to print in console"<<std::endl;
    std::string user_response;
    std::cin>>user_response;
    if (user_response == "file"){
        std::string path = print_data_filename();
        std::ofstream fout(path);
        for (int iter = 0; iter < size_; iter++)
            fout << iter << ": " << data_[iter] << std::endl;
        std::cout<<"data was put in "<<path<<std::endl;
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
    LOG_INFO("VECTOR COPIED");
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
    LOG_INFO("MEMORY ALLOCATED");
    return where_to_create;
}

template <typename T>
std::string Vector<T>::dump() const{
    std::ostringstream out_string;
    out_string<<"size: "<<size_<<std::endl;
    out_string<<"data pointer: "<<data_<<std::endl;
    if (data_!=NULL && size_!=0) {
        out_string<<"data:"<<std::endl;
        for (int iter=0; iter < size_; iter++)
            out_string<<iter<<':'<<data_[iter]<<std::endl;
    }
    return out_string.str();
}

template <typename T>
std::string Vector<T>::print_data_filename() const{
    std::ostringstream file_path;
    file_path<<"../data";
    file_path<<time(NULL)<<".txt";
    return file_path.str();
}