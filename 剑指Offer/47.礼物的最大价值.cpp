//动态规划
//状态转移方程: dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + grid[i][j]
//利用grid就地保存dp,将空间复杂度从O(MN)降至1
//时间复杂度O(MN)
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(i == 0 && j == 0) continue;
                if(i == 0) grid[0][j] += grid[0][j-1];
                else if(j == 0) grid[i][0] += grid[i-1][0];
                else grid[i][j] += max(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};
