//思路:基于字符串拼接,重新定义排序规则
//若mn < nm, 则字符串m < n
//eg:对于"30" "3"来说 "303" < "330",所以 "30" < "3"
//然后按高位越小越好规则排序拼接
//可以利用lambda表达式改写sort方法
//时间复杂度NlogN 空间复杂度N
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for(auto i:nums){
            strs.push_back(to_string(i));
        }
        sort(strs.begin(), strs.end(), [](string &s1, string &s2){return s1 + s2 < s2 + s1;});
        string rst = "";
        for(auto i:strs){
            rst += i;
        }
        return rst;
    }
};
