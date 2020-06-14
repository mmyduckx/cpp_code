//思路:
 // A[.[B]][e|EC] or .B[e|EC]
class Solution {
public:
    bool isInteger(string &s, int &i){
        if(s[i] == '+' || s[i] == '-')
            ++i;
        return isUnsignedInt(s, i);
    }

    bool isUnsignedInt(string &s, int &i){
        //1244.
        int j = i;
        while( i < s.size()){
            if(s[i] > '9' || s[i] < '0'){
                break;
            }
            ++i;
        }
        return j < i; 
    }


    bool isNumber(string s) {
        if(s.empty()) return false;
        int i = 0;
        while(s[i] == ' '){
            ++i;
        }
        if(i == s.size()) return false;
        bool rst = isInteger(s, i);

        if(i < s.size() && s[i] == '.'){ 
            ++i;
            rst = isUnsignedInt(s, i) || rst; // A.B 或.B或 A.几种可能的结果都可以
        }

        if( i < s.size() && (s[i] == 'e' || s[i] == 'E')){
            ++i;
            rst = isInteger(s, i) && rst; // A.B|B + [e|EC]
        }

        while(i < s.size() && s[i] == ' '){
            ++i;
        }

        return rst && i == s.size();
    }
};
