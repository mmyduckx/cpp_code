//思路:
//依次从第一个char和后面的char互换swap(s[index],s[i])
//递归调用permutation(s, index+1)进行回溯
//用unordered_set去重
class Solution {
public:
    unordered_set<string> hashset;
    void permutation(string s, int index){
        if(index == s.size())
            hashset.insert(s);
        for(int i = index; i < s.size(); ++i){
            if(i != index && s[i] == s[index]) continue;
            swap(s[index], s[i]);
            permutation(s, index + 1);
        }
    }

    vector<string> permutation(string s) {
        if(s.empty()) return vector<string>(0);
        permutation(s, 0);
        vector<string> rst(hashset.begin(), hashset.end());
        return rst;
    }

};
