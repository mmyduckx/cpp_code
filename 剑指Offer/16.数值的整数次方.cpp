//思路:通过指数幂方法将复杂度从n变为logn
//eg:myPow(10,9) 9 = 1001 10^9 = 10^8 * 10^1
//通过移位并每次使基数自乘 x = x * x;
//10 100 10000 100000000
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        bool flag = true;
        long num = n;
        if(num < 0){
            num = -num;
            flag = false;
        }
        double rst = 1;
        while(num){
            if(num&1) rst *= x;
            x *= x;
            num = num >> 1;
        }
        return flag?rst:1/rst;
    }
};
