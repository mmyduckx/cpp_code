//思路1: 首先可以先把前几个结果写出来找规律
// 2: 1 * 1
// 3: 2 * 1 > 1 * 1 * 1
// 4: 2 * 2 > 3 * 1
// 5: 3 * 2 > 4 * 1
// 6: 3 * 3 > 2 * 2 * 2
// 7: 3 * 4 > 5 * 2 
// 8: 3 * 3 * 2 > 4 * 4
//规律 能分3的分3,不能分3的分4,最后再分1,可以得到最大积

//思路2:
//用动态规划, dp[i] = max(dp[i], max((i-j)*j,  dp[i-j]*j),) 
//                  维持原状不剪,从j处减,剩i-j不剪, 从j处减,剩i-j继续减
class Solution {
public:
    int cuttingRope(int n){
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 1;
        // 3: 2,1
        // for(int i = 3; i <= n; ++i){
        //     for(int j = 1; j < i; ++j){
        //         dp[i] = max(dp[i],max((i-j)*j, dp[i-j]*j));
        //     }
        // }
        //优化后:
        for(int i = 3; i <=n; ++i){
            // dp[i] = max(dp[i], (i-3)*3, (i-2)*2, dp[i-3]*3, dp[i-2]*2);
            dp[i] = max(dp[i], max(max((i-3)*3,(i-2)*2), max(dp[i-3]*3,dp[i-2]*2)));
        }
        return dp[n];
    }



    // int cuttingRope(int n) {
    //     if(n == 2) return 1;
    //     if(n == 3) return 2;
    //     if(n == 4) return 4;
    //     if(n % 3 == 0){
    //         int r = n / 3;
    //         return pow(3, r);
    //     }
    //     else{
    //         if((n-4) % 3 == 0){ // pow(3,n)*4形式
    //             int r = (n-4) / 3;
    //             return pow(3,r) * 4;
    //         }
    //         else{  // pow(3,n)*2形式
    //             int r = (n-2) / 3;
    //             return pow(3,r) * 2;
    //         }
    //     }
    // }
    
};
