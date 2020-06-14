//思路:
//1.蛮力 时间复杂度N^2
//2.哈希表 时间复杂度N 空间复杂度N
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> hashmap;
        for(auto ch : s) ++hashmap[ch];
        for(auto ch : s) if(hashmap[ch] == 1) return ch;
        return ' ';
    }
};
