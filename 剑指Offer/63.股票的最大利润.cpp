//1. 蛮力法 时间复杂度O(N^2) 超时
//2. 动态规划
// 第i日的最大利润 dp[i] = max(dp[i-1], prices[i] - min(prices[0...i-1]))
// 时间复杂度O(N) 空间复杂度O(N) 可以优化到O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;

        vector<int> dp(prices.size());
        dp[0] = 0;
        // int dp = 0;
        int min = prices[0];
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i - 1] < min) min =  prices[i - 1];
            dp[i] = max(dp[i - 1], prices[i] - min);
            //dp = max(dp, prices[i] - min);
        }

        return *max_element(dp.begin(), dp.end());
        //return dp;
    }
};
