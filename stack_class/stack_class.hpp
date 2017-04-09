template <typename T>
Stack<T>::Stack(): size_(0){}

template <typename T>
const typename Stack<T>::value_type* Stack<T>::top(){
    ASSERT_OK(ok());
    if (this->empty()){
        ASSERT_OK(ok());
        return NULL;
    }
    ASSERT_OK(ok());
    return &(data_[size_-1]);
}

template <typename T>
bool Stack<T>::push(const value_type& value_to_push){
    ASSERT_OK(ok());
    if (size_>=capacity_) {
        ASSERT_OK(ok());
        return false;
    }
    data_[size_]=value_to_push;
    size_++;
    ASSERT_OK(ok());
    return true;
}

template <typename T>
bool Stack<T>::pop(){
    ASSERT_OK(ok());
    if (this->empty())
        return false;
    --size_;
    ASSERT_OK(ok());
    return true;
}

template <typename T>
bool Stack<T>::empty(){
    ASSERT_OK(ok());
    if (size_==0) {
        ASSERT_OK(ok());
        return true;
    }
    ASSERT_OK(ok());
    return false;
}

template <typename T>
size_t Stack<T>::size(){
    ASSERT_OK(ok());
    return size_;
}

template <typename T>
size_t Stack<T>::capacity() {
    ASSERT_OK(ok());
    return capacity_;
}

template <typename T>
bool Stack<T>::ok(){
    return size_<=capacity_;
}

template <typename T>
string Stack<T>::dump(){
    ostringstream out_string;
    out_string<<"size: "<<size_<<endl;
    for (int i=0;i<size_;i++){
        out_string<<i<<": "<<data_[i]<<endl;
    }
    return out_string.str();
}
