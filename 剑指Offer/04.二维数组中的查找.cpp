//思路:
//当target大于每行最后一个, 删除整行
//当target小于每行最后一个, 删除整列
//时间复杂度O(m+n)
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() == true) return false;

        int row = 0;
        int col = matrix[0].size() - 1;
        while(row < matrix.size() && col >= 0){
            if(target > matrix[row][col]){
                ++row;
            }
            else if(target < matrix[row][col]){
                --col;
            }
            else{
                return true;
            }
        }
        return false;
    }
};

