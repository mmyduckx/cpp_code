//将B[i]分为两部分 A[0...i-1] 和 A[i+1...n-1]
//构建这两部分数组 相乘
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> b(n);
        vector<int> c(n,1);
        vector<int> d(n,1);
        for(int i = 1; i < n; ++i){
            c[i] = c[i - 1] * a[i - 1];
            d[n - i - 1] = d[n - i] * a[n - i];
        }
        for(int i = 0; i < n; ++i){
            b[i] = c[i] * d[i];
        }
        return b;
    }
};
