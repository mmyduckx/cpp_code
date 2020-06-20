//1.整体reverse一次 内部reverse一次
//2.利用尾部双指针从后往前截取word然后拼接
class Solution {
public:
    string reverseWords(string s) {
    string rst = "";
    if(s.empty()) return rst;
    int i = s.size() - 1;
    int len = 0;
    while(i >= 0){
        if(s[i] != ' '){
            ++len;
            --i;
        }
        else if(s[i] == ' ' && len != 0){
            rst += s.substr(i + 1, len) + " ";
            len = 0;
            --i;
        }
        else if(s[i] == ' ' && len == 0){
            --i;
        }
    }
    if(len != 0) {
        rst += s.substr(0, len);
    }
    else {
        if(rst.size() > 0) rst.erase(rst.size()-1, 1);
    }
    return rst;
    }
};
