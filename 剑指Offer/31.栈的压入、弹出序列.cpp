//思路:
//引入一个辅助栈s模拟
//每次按pushed顺序压入s并判断s.top()是否与弹出序列相同
//结束条件:当pushed压完后,若s为空,则说明压入的全都弹出了,即匹配
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j = 0;
        for(int i = 0; i < pushed.size(); ++i){
            s.push(pushed[i]);
            while(!s.empty() && s.top() == popped[j]){
                s.pop();
                ++j;
            }
        }
        return s.empty();
    }
};
