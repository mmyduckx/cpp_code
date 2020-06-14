//思路:
//左右各设置一个index 遇到奇偶交换
//结构类似快排
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.empty()) return nums;
        int i = 0;
        int j = nums.size() - 1;
        while(i < j){
            while(i < j && nums[i] % 2 == 1) ++i;
            while(i < j && nums[j] % 2 == 0) --j;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            ++i;
            --j;
        }
        return nums;
    }
};
