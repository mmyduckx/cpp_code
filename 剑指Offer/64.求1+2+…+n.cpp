//思路:利用逻辑运算符 改写递归出口
//原递归 
// f(n) = n + f(n-1)
class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n-1));
        return n;
    }
};
