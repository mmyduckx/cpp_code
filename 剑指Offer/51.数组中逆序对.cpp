//思路:利用归并排序的思路  
//每次merge时计算逆序对
//count = merge(l, mid) + merge(mid+1, r) + count_in_cur
// 2 3 5 7 | 1 4 6 8 10
class Solution {
public:
    int mergeSort(vector<int>& nums, vector<int>& temp, int l, int r){
        //做归并并计算逆序对
        if(l >= r) return 0; //不存在逆序对
        int mid = l + (r-l)/2;
        int count = mergeSort(nums, temp, l, mid) + mergeSort(nums, temp, mid+1, r);
        //[l...mid]有序 和[mid+1...r]有序 计算逆序对
        int i = l;
        int j = mid+1;
        int pos = l;
        while(i <= mid && j <= r){
            if(nums[i] <= nums[j]){
                temp[pos++] = nums[i++];
            }
            else{
                temp[pos++] = nums[j++];
                count += mid + 1 - i;
            }
        }
        //i > mid || j > r
        while(i <= mid){
            temp[pos++] = nums[i++];
        }
        while(j <= r){
            temp[pos++] = nums[j++];
        }
        //把排好序的temp复制到nums数组
        copy(temp.begin() + l, temp.begin() + r + 1, nums.begin() + l);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        vector<int> temp(nums.size());
        return mergeSort(nums, temp, 0, nums.size() - 1);
    }
};
