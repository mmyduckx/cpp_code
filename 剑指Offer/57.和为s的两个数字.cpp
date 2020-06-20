//思路:
//1.蛮力法 复杂度N*N
//2.双指针左右遍历 复杂度N
//优化: 可以每次先二分查找 再双指针 最好情况logN 最坏情况N
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while(i < j){
            if(nums[i] + nums[j] < target) ++i;
            else if(nums[i] + nums[j] > target) --j;
            else return {nums[i], nums[j]};
        }
        return vector<int>(2);
    }
};
