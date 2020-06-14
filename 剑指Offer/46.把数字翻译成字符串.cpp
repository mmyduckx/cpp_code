//思路:动态规划
//dp[i] = dp[i-1] + dp[i-2](if(0<=str[i-1]+str[i]<=25))
//时间复杂度为num的位数N 即log(num) 空间复杂度N
//可以用滚动数组将动态规划空间复杂度从O(N)降至O(1) 但to_string(num)仍是O(N)
class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        vector<int> dp(str.size());
        dp[0] = 1;
        if(str.size() == 1) return dp[0];
        string pre = str.substr(0,2);
        dp[1] = (pre >= "10" && pre <="25")?2:1;
        for(int i = 2; i < str.size(); ++i){
            dp[i] = dp[i-1];
            pre = str.substr(i-1, 2);
            if(pre >= "10" && pre <="25"){
                dp[i] += dp[i-2];
            }
        }
        return dp[str.size()-1];
    }
};
