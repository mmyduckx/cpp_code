//思路:依然是二分查找思想 时间复杂度logN 空间复杂度1
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j){
            int mid = i + (j - i) / 2;
            if(nums[mid] == mid) i = mid + 1;
            else j = mid - 1;
        }
        return i;
    }
};
