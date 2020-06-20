//思路: bits[32]中储存所有位的和, 然后对各位余3, 将各位结果拼接即为出现一次的数
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32);
        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j < 32; ++j){
                bits[j] += nums[i]&1; //更新第j位
                nums[i] >>= 1;         //nums右移,准备更新j+1位
            }
        }
        int rst = 0;
        for(int i = 0; i < 32; ++i){
            rst <<= 1;
            rst |= bits[31 - i]%3;
        }
        return rst;
    }
};
