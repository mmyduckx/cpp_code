//思路:相同数异或结果为0 
//[1,2,10,4,1,4,3,3]异或结果为[2^10]
//可以拿得到的异或结果的非0最低位来对原数组分组 则一组有2 一组有10 其余都是出现两次的数字
//再对两组分别异或即可
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int rst = 0;
        //对数组异或
        for(auto i : nums){
            rst ^= i;
        }
        //找异或结果非0最低位
        int div = 1;
        while((rst & div) == 0){
            div <<= 1;
        }
        int num1 = 0;
        int num2 = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] & div){
                num1 ^= nums[i];
            }
            else
                num2 ^= nums[i];
        }
        return {num1, num2};
    }
};
