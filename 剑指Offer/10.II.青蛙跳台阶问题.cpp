//思路: 递推式f(n) = f(n-2) + f(n-1)
class Solution {
public:
    int numWays(int n) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        int rst1 = 1;
        int rst2 = 1;
        int temp;
        for(int i = 2; i <= n; ++i){
            temp = rst2;
            rst2 = (rst2+rst1)%1000000007;
            rst1 = temp;
        }
        return rst2;
    }
};
