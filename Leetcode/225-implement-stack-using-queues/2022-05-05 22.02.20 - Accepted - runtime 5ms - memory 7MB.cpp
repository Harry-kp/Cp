class MyStack {
public:
    queue<int> org,tmp;
    
    MyStack() {
        
    }
    
    void push(int x) {
        if(org.empty())
            org.push(x);
        else{
            while(!org.empty())
            {
                tmp.push(org.front());
                org.pop();
            }
            org.push(x);
        while(!tmp.empty())
            {
                org.push(tmp.front());
                tmp.pop();
            }
        }
    }
    
    int pop() {
        int tmp = org.front();
        org.pop();
        return tmp;
    }
    
    int top() {
        return org.front();
    }
    
    bool empty() {
        return org.empty();
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