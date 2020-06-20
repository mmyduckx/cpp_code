//反转三次 :前半str 后半str 整个str
//就地原则 空间复杂度O(1) 时间复杂度O(N)
class Solution {
public:
    void reverse_string(string& s, int i, int j){
        while(i < j)
            swap(s[i++], s[j--]);
    }
    
    string reverseLeftWords(string s, int n) {
        if(s.size() <= 1) return s;
        reverse_string(s, 0, n - 1);
        reverse_string(s, n, s.size() - 1);
        reverse_string(s, 0, s.size() - 1);
        return s;
    }

};
