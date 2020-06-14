//思路:分别固定每位, 并计算每位为1的情况
//5014
//cur = 0,count = high * digit + 0
//cur = 1,count = high * digit + low+1
//cur > 1,count = high * digit + digit
//时间复杂度logn 空间复杂度1
class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        long digit = 1;
        while(n/digit != 0){// 5 0 14
            long high = n / (digit*10);
            long cur = (n / digit) % 10;
            long low = n - n/digit * digit;
            
            if(cur ==0) count += high * digit;
            else if(cur == 1) count += high * digit + low + 1;
            else if(cur > 1) count += high * digit + digit;

            digit *= 10;
        }
        return count;
    }
};
