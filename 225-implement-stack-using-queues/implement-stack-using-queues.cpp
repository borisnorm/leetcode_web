class MyStack {
public:
    queue<int> my_queue;
    MyStack() {
        
    }
    
    void push(int x) {      
      my_queue.push(x);
    }
    
    int pop() {
      int pop_cnt = my_queue.size();
      int res = -1;
      for (int i = 0; i < pop_cnt; i++)
      {
        int tmp = my_queue.front();
        my_queue.pop();
        if (i != (pop_cnt-1))
          my_queue.push(tmp);
        else
          res = tmp;  
      }    
      return res;  
    }
    
    int top() {
      return my_queue.back();
    }
    
    bool empty() {
      return my_queue.empty();    
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */