//思路
//利用滑动窗口思想:双指针i,j
//当s[j]无重复时,j++
//当s[j]有重复时,i为上次重复位置+1 与 当前i中靠右的一个 如:abcba
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int rst = 0;
        if(s.empty()) return rst;
        unordered_map<char,int> hashmap;
        int i = 0;
        for(int j = 0; j < s.size(); ++j){
            if(hashmap.find(s[j]) != hashmap.end()){ //存在重复的
                i = max(i, hashmap[s[j]] + 1); //可能存在重复元素在左指针之前的情况
            }
           hashmap[s[j]] = j;
           rst = max(rst, j - i + 1);
        }
        return rst;
    }
};
