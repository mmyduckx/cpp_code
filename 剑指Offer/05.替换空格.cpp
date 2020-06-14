//思路:在原string基础上扩容空格数*2
//倒着遍历string把每个char放进去
//当char为空格时替换为%20
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        for(auto i : s){
            if(i == ' '){
                count++;
            }
        }
        if(count == 0) return s;
        else{
            int n = s.size() - 1;
            s.resize(s.size() + count*2);
            for(int i = s.size()-1; i >= 0; --i){
                if(s[n] != ' '){
                    s[i] = s[n];
                }
                else{
                    s[i--] = '0';
                    s[i--] = '2';
                    s[i] = '%';
                }
                --n;
            }
            return s;
        }
    }
};
