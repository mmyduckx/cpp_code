//思路:滑动窗口
//利用左右指针 当sum < target, ++j 当 sum > target ++i
//时间复杂度 O(N) 空间复杂度O(N)
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> rst;
        vector<int> nums(target/2 + 1);
        for(int i = 0; i < nums.size(); ++i){
            nums[i] = i + 1;
        }
        int i = 1;
        int j = 2;
        int sum = i + j;
        int mid = target/2;
        while(i <= mid){
            if(sum < target){
                ++j;
                sum += j;
            }
            else if(sum > target){
                sum -= i;
                ++i;
            }
            else{// [i...j] == target
                vector<int> v(nums.begin() + i - 1, nums.begin() + j);
                rst.push_back(v); 
                ++j;
                sum += j;
            }
        }

        return rst;
    }
};
