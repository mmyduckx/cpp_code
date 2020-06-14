class Solution {
public:
    vector<int> printNumbers(int n) {
        int a = pow(10,n);
        vector<int> rst;
        for(int i = 1;i < a; ++i){
            rst.push_back(i);
        }
        return rst;
    }
};
