//思路:
//1.排序 去中位数 时间复杂度N*logN
//2.利用哈希表统计出现次数 时间复杂度N 空间复杂度N
//3.利用摩尔投票(本题最佳解法) 每次出现元素相同poll++ 不同poll-- 当归零后更换当前对象
// 因为有一个数字出现次数过半 所以最后一定会胜出(即poll>0))
// 时间复杂度N 空间复杂度1
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int poll = 1;
        int winner = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == winner) ++poll;
            else --poll;

            if(poll == 0) {
                winner = nums[i];
                poll = 1;
            }
        }
        return winner;
    }
};
