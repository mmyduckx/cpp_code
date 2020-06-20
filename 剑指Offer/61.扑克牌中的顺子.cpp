//思路:
//1.除0外无重复
//2.保存最大值和最小值(不含0)
//3.看最大最小值差值是否<5
// ABCDE
// 0BCDE || A0CDE
// 00CDE || A00DE
//时间复杂度O(N) 本题N = 5;即O(1)
//空间复杂度O(N) 
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int min = 999;
        int max = -1;
        unordered_set<int> hashset;
        for(auto i : nums){
            if(i == 0) continue;
            if(i < min) min = i;
            if(i > max) max = i;
            if(hashset.find(i) != hashset.end()) return false;
            else hashset.insert(i);
        }
        return max - min < 5;
    }
};
