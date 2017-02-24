class Stack{
    public:

    typedef float value_type;

    Stack();
    ~Stack(){ }

    value_type top();
    bool empty();
    value_type pop();
    bool push(value_type value_to_push);

    private:

    static const size_t capacity_=6;
    value_type data_[capacity_];
    size_t size_;

};

Stack::Stack(){
    size_=0;
    data_[capacity_];
}

Stack::value_type Stack::top(){
    value_type top_value;
    top_value = data_[size_-1];
    return top_value;
}

bool Stack::push(value_type value_to_push){
    if (size_>=capacity_)
        return false;
    data_[size_]=value_to_push;
    size_++;
    return true;
}

Stack::value_type Stack::pop(){
    value_type top_value;
    top_value = data_[--size_];
    return top_value;
}
