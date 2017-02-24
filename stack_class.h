//------------------------------
//!@file stack_class
//!
//!@author theSonOfMan
//------------------------------

class Stack{
	public:
		
		typedef float stk_value_type;
		
		Stack();
		
		~Stack();
		
		bool top();
		bool empty();
		bool pop();
		bool push(stk_value_type value_to_push);
		
		size_t capacity();
		size_t size();
		
		
	private:
		static const size_t capacity_=6;
		stk_value_type data_[capacity_];
		size_t size_;
	
};


