//思路: 找规律
// 1~9      9*1 = 9
// 10~99   90*2 = 180
// 100~999 900*3 = 2700
// eg: 201
// n - 9 - 180 - 2700 <0 break
// start = n - 9 -180 = 12
// digit = 3 
// rst = 10^digit + start/digit - 1 = 103 加上偏移量得到的数
// 偏移量 = start % digit = 0
// rst即为103的末位3
class Solution {
public:
    int findNthDigit(int n) {
        int digit = 0; //n所在的数的位数
        long num = n;  //int太小了 用long保存
        long start = n;
        while(num >= 0){
            start = num;
            num -= 9 * pow(10, digit) * (digit+1);
            ++digit;
        }
        int i = start % digit; //获得偏移位置
        int rst = pow(10, digit-1) +  start/digit - 1; //获得偏移所基于的数的前一个数
        if(i == 0){ //正好是获得数的末位
            rst = rst % 10;
        }
        else{ //偏移是基于下一个数
            rst++;
            string str = to_string(rst);
            rst = str[i-1] - '0';
        }
        return rst;
    }
};
