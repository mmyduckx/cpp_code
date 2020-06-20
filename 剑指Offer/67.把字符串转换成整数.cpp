//思路: 先删前空格, 再判断+/-符合 再对string转int还原
//注意在循环里判断是否越界
class Solution {
public:
    int strToInt(string str) {
        int i = 0;
        int j = 0;
        while(str[i] == ' ') ++i;
        int sign = 1;
        if(str[i] == '-' || str[i] == '+') {
            if(str[i] == '-') sign = -1;
            ++i;
        }
        long num = 0;

        while(i < str.size() && str[i] >= '0' && str[i] <= '9'){
            //if(res>INT_MAX/10 || (INT_MAX/10==res && r>7))//判断当前结果是否溢出,溢出直接返回最大值或者最小值
            num *= 10;
            num += (str[i] - '0') * sign;
            if(num > pow(2,31) - 1) return pow(2,31) - 1;
            else if(num < -pow(2,31)) return -pow(2,31);
            ++i;
        }
        return num;
    }
};
