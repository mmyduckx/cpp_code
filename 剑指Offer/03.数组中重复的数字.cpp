//思路:
//把nums[i]的值放到下标为i的位置(swap(nums[i],nums[nums[i]])), 若没有重复,则n个值正好填满n个位置
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0;i < nums.size();){
            if(nums[i] == i){
                ++i;
            }
            else{
                if(nums[nums[i]] == nums[i]){
                    return nums[i];
                }
                else{
                    int temp = nums[nums[i]];
                    nums[nums[i]] = nums[i];
                    nums[i] = temp;
                }
            }
        }
        return -1;
    }
};


