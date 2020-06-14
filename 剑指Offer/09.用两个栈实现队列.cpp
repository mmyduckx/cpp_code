//思路:用两个栈s1,s2
//每次插入把s1全丢进s2,插入新元素到s2,再丢回s1
class CQueue {
public:
    stack<int> s1;
    stack<int> s2;
    CQueue() {
    }
    
    void appendTail(int value) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(value);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int deleteHead() {
        if(s1.empty()){
            return -1;
        }
        else{
            int front = s1.top();
            s1.pop();
            return front;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
