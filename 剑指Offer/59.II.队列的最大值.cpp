//思路: 如果是实现最大栈 可以用辅助栈实现
// 但是对于本体最大队列, 我们发现无法用辅助队列或辅助栈实现
// 要实现一个单调非严格递减数据结构 我们必须要使用一个双向队列deque
//时间复杂度：O(1)O(1)（插入，删除，求最大值）
//插入操作虽然看起来有循环 但由于每个数字只会出队一次，因此对于所有的n个数字的插入过程，对应的所有出队操作也不会大于n次。因此将出队的时间均摊到每个插入操作上，时间复杂度为O(1)
//空间复杂度：O(n)，需要用队列存储所有插入的元素
class MaxQueue {
public:
    queue<int> q;
    deque<int> dq;
    MaxQueue() {
    }
    
    int max_value() {
      if(dq.empty()) return -1;
      else return dq.front();
    }
    
    void push_back(int value) {
      q.push(value);
        while(!dq.empty() && dq.back() < value){
            dq.pop_back();
        }
        dq.push_back(value);
    }
    
    int pop_front() {
        if(q.empty()) return -1;
        else{
            if(q.front() == dq.front()) dq.pop_front();
            int front = q.front();
            q.pop();
            return front;
        }
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
