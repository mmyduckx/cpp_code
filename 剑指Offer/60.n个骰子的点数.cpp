//思路:动态规划
//对于i个骰子掷出点数j出现的次数: dp[i][j] += dp[i-1][j-1...6];
//时间复杂度 O(N^2) 空间复杂度O(N^2)
// class Solution {
// public:
//     vector<double> twoSum(int n) {
//         vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1));
//         for(int i = 1; i <= 6; ++i){
//             dp[1][i] = 1;
//         }
//         for(int i = 2; i <= n; ++i){
//             for(int j = i; j <= 6 * i; ++j){
//                 for(int val = 1; val <= 6; ++val){
//                     if(j < val) break;
//                     dp[i][j] += dp[i-1][j-val];   
//                 }
//             }
//         }
//         double total = pow(6, n);
//         vector<double> rst;
//         for(int i = n; i <= 6 * n; ++i){
//             rst.push_back(dp[n][i] / total);
//         }
//         return rst;
//     }
// };

//继续优化空间复杂度到O(N)
class Solution {
public:
    vector<double> twoSum(int n) {
        vector<int> dp(6 * n + 1);
        for(int i = 1; i <= 6; ++i){
            dp[i] = 1;
        }
        for(int i = 2; i <= n; ++i){
            for(int j = i * 6; j >= i; --j){
                dp[j] = 0; //必须把原先存放的n-1个骰子的数据置0，否则累加出错
                for(int val = 1; val <= 6; ++val){
                    if(j - val < i - 1) break; //n-1个骰子的最小值就是n-1，不会比这再小，因此此处的判据是i-1，而不是0；
                    dp[j] += dp[j - val]; 
                }
            }
        }
        double total = pow(6,n);
        vector<double> rst;
        for(int i = n; i <= 6 * n; ++i){
            rst.push_back(dp[i] / total);
        }
        return rst;
    }
};
