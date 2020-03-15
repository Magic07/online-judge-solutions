class CustomStack {
public:
    int maxSize_;
    deque<int> myStack;
    CustomStack(int maxSize):maxSize_(maxSize) {}
    
    void push(int x) {
      if(myStack.size()<maxSize_){
        myStack.push_back(x);
      }
    }
    
    int pop() {
      if(!myStack.empty()){
        int x=myStack.back();
        myStack.pop_back();
        return x;
      }
      return -1;
    }
    
    void increment(int k, int val) {
      for(int i=0;i<min(k, (int)myStack.size());i++){
        myStack.at(i)+=val;
      }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */