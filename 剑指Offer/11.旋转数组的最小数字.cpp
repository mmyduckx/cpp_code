//思路:
//1.sort() 复杂度:n*logn
//2.遍历比较逆序 复杂度:n
//3.二分法 复杂度:logn
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l = 0;
        int r = numbers.size() - 1;
        int mid;
        while(l < r){
            mid = (l + r) / 2;
            if(numbers[mid] <= numbers[r]) --r;
            else ++l;
        }
        return numbers[l];
    }
};
