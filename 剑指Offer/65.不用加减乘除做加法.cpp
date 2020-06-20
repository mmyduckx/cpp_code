//思路:
//12: 1100
//15: 1111
//1. 12^15 做不进位加法:0011
//2. (12&15) << 1 做进位加法: 1 1000
//两者相加,即重复步骤1,2; 直至没有进位
class Solution {
public:
    int add(int a, int b) {
        while(b != 0){
            int sum = a ^ b;
            // 负数左移会在低位补1，所以转化为无符号整数
            int carry = (unsigned int)(a & b) << 1; 
            a = sum;
            b = carry;
        }
        return a;
    }
};
