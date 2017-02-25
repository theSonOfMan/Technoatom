#define ASSERT_OK()\
    if (!ok())\
    {\
        dump();\
        assert(!"object is ok");\
    }\

class Stack{
    public:

    typedef float value_type;

    Stack();
    ~Stack(){ }

    value_type top();
    bool empty();
    value_type pop();
    bool push(value_type value_to_push);
    size_t size();
    bool ok();
    void dump();

    private:

    static const size_t capacity_=6;
    value_type data_[capacity_];
    size_t size_;

};

Stack::Stack(){
    size_=0;
}

Stack::value_type Stack::top(){
    ASSERT_OK();
    value_type top_value;
    top_value = data_[size_-1];
    ASSERT_OK();
    return top_value;
}

bool Stack::push(value_type value_to_push){
    ASSERT_OK();
    if (size_>=capacity_) {
        ASSERT_OK();
        return false;
    }
    data_[size_]=value_to_push;
    size_++;
    ASSERT_OK();
    return true;
}

Stack::value_type Stack::pop(){
    ASSERT_OK();
    value_type pop_value;
    pop_value = data_[--size_];
    ASSERT_OK();
    return pop_value;
}

bool Stack::empty(){
    ASSERT_OK();
    if (size_==0) {
        ASSERT_OK();
        return true;
    }
    ASSERT_OK();
    return false;
}

size_t Stack::size(){
    ASSERT_OK();
    return size_;
}

bool Stack::ok(){
    return size_<=capacity_;
}

void Stack::dump(){
    ofstream dump_file;
    dump_file.open("/Users/home/Technoatom/stack_class/dump.txt");
    dump_file<<"size = "<<size_<<endl<<"data:"<<endl;
    for (int i=0;i<capacity_;i++) {
        dump_file<<i<<' ';
        dump_file << data_[i] << endl;
    }
    dump_file.close();
}
