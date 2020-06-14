class Solution {
public:
//解法1:直接右移 最低位与1
//复杂度logn
    // int hammingWeight(uint32_t n) {
    //     int count = 0;
    //     while(n != 0){
    //         count += n&1;
    //         n = n >> 1;
    //     }
    //     return count;
    // }

// 解法2: 用(n-1)&n
// 复杂度M(为数位中1的个数)
// (n-1) & n 表示每次做与运算后消除最低位的一个数位1 较高位不变
// 1110 0010 & 1110 0001 = 1110 0000

    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n != 0){
            n &= (n-1);
            ++count;
        }
        return count;
    }


};
