//思路:
//动态规划
//dp[i]代表以nums[i]结尾的最大值
//dp[i] = dp[i-1] + nums[i] (dp[i-1] >= 0)
//dp[i] = nums[ (dp[i-1] < 0)]
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            dp[i] = max(dp[i-1], 0) + nums[i];
        }
        return *max_element(dp.begin(), dp.end());
    }
};
