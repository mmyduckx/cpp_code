//思路:
//丑数 = 2^x * 3^y * 5^z
//nums[i] = min(nums[a]*2,nums[b]*3,nums[c]*5)
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(n);
        int a = 0;
        int b = 0;
        int c = 0;
        int num = 1;
        nums[0] = 1;
        for(int i = 1; i < n; ++i){
            num = min(min(nums[a] * 2, nums[b] * 3), nums[c] * 5);
            if(num == nums[a]*2) ++a;
            if(num == nums[b]*3) ++b;
            if(num == nums[c]*5) ++c;
            nums[i] = num;
        }
        return nums[n-1];
    }
};
