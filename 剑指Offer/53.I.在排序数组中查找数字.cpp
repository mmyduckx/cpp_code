//思路:因为数组已经排序,直接二分查找找左右边界
//时间复杂度logN 空间复杂度1
//若数组未排序,可以用哈希表
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int i = 0;
        int j = nums.size() - 1;
        //找右边界
        while(i <= j){
            int mid = i + (j - i) / 2;
            if(nums[mid] <= target) i = mid + 1;
            else j = mid - 1;
        }
        // 若target存在,j为target最后一个元素 i为右边界
        int right = i;
        if(j >=0 && nums[j] != target) return 0; //target不存在 直接返回
        
        i = 0;
        j = nums.size() - 1;
        while(i <= j){
            int mid = i + (j - i) / 2;
            if(nums[mid] >= target) j = mid - 1;
            else i = mid + 1;
        }
        int left = j;
        return right - left - 1;
    }
};
