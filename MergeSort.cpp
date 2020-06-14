#include <iostream>
#include <vector>
using namespace std;
void mergeSort(vector<int> &nums, vector<int> &temp, int l, int r){
    //只有一个元素
    if(l >= r) return;
    int mid = l + (r - l) / 2; //防止溢出
    //对左右两边归并
    mergeSort(nums, temp, l, mid);
    mergeSort(nums, temp, mid+1, r);
    //合并
    int i = l;
    int j = mid+1;
    int pos = l;
    while(i <= mid && j <= r){
        if(nums[i] <= nums[j]) temp[pos++] = nums[i++];
        else temp[pos++] = nums[j++];
    }
    // i > mid || j > r
    while(i <= mid){
        temp[pos++] = nums[i++];
    }
    while(j <= r){
        temp[pos++] = nums[j++];
    }
    //将排序好的temp复制到原数组
    copy(temp.begin() + l, temp.begin() + r + 1, nums.begin() + l);
    return;
}

int main(){
    vector<int> nums{4,3,5,6,7,1,2,8}; 
    vector<int> temp(nums.size());
    mergeSort(nums, temp, 0 , nums.size() - 1);
    for(auto i : nums) cout << i << " ";
}