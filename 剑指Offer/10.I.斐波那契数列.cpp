//思路:使用变量暂时保存每次的a,b
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int a = 0;
        int b = 1;
        int temp;
        for(int i = 2; i <= n; ++i){
            temp = b;
            b = (b+a) % 1000000007;
            a = temp;
        }

        return b;
    }
};
