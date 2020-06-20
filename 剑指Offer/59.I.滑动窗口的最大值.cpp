//思路:利用双向队列deque, 使deque保持非严格递减
//当nums[i] >= deque.back, 所以小于nums[i]的尾部pop
//当nums[i] < deque.back 将元素push_back到队尾
//注意判断头部<=i-k时要弹出,此时表示已出界
//时间复杂度 O(N) 空间复杂度O(N)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> rst;
        deque<int> deq;
        for(int i = 0; i < nums.size(); ++i){
            if(!deq.empty() && deq.front() == i - k)
                deq.pop_front();

            while(!deq.empty() && nums[i] >= nums[deq.back()]){
                deq.pop_back();
            }    
            deq.push_back(i);

            if(!deq.empty() && i >= k - 1){
                rst.push_back(nums[deq.front()]);
            }
        }
        return rst;
    }
};
