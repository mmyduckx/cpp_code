//思路:
//界定上下左右l,r,t,b
//依次 左右 上下 右左 下上扫描
//结束条件: 每个方向扫描后判断界定值
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return vector<int>(0);
        vector<int> rst = vector<int>(matrix.size()*matrix[0].size());
        int l = 0;
        int r = matrix[0].size() - 1;
        int t = 0;
        int b = matrix.size() - 1;
        int j = 0;
        while(j < rst.size()){
            for(int i = l; i <= r; ++i){ // left to right
                rst[j++] = matrix[t][i];
            }
            ++t;
            if(t > b) break;
            for(int i = t; i <= b; ++i){ // top to bottom
                rst[j++] = matrix[i][r];
            }
            --r;
            if(r < l) break;
            for(int i = r; i >= l; --i){ // right to left
                rst[j++] = matrix[b][i];
            }
            --b;
            if(b < t) break;
            for(int i = b; i >= t; --i){
                rst[j++] = matrix[i][l];
            }
            ++l;
            if(l > r) break;
        }
        return rst;
    }
};
