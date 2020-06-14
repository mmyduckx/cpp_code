//1.利用快排思想(快速选择算法)
//时间复杂度 期望为N, 最坏情况下的时间复杂度为N*logN
//空间复杂度 期望为logN, 最坏情况为N
//每次partition后的值为m
//若m == k,则[0,m)即为所求最小k个数
//若m < k, 则还需要对右边进行扩大partition
//若m > k, 则需要对左边进行缩小partition
class Solution {
public:
    int partition(vector<int>& arr, int l, int r){
        if(l >= r) return l;
        int pivot = arr[l];
        while(l < r){
            while(l < r && arr[r] >= pivot){
                --r;
            }
            arr[l] = arr[r];
            while(l < r && arr[l] <= pivot){
                ++l;
            }
            arr[r] = arr[l];
        }
        arr[l] = pivot;
        return l;
    }

    void partitionArray(vector<int>& arr, int l, int r, int k){
        int m = partition(arr, l, r);
        if(m < k){ //在m的右边找k
            partitionArray(arr, m+1, r, k);
        }
        else if(m > k){ //在m的左边找k
            partitionArray(arr, l, m-1, k);
        }
        else return;
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.empty()) return vector<int>(0);
        partitionArray(arr, 0, arr.size()-1, k);
        vector<int> rst(arr.begin(), arr.begin()+k);
        return rst;
    }
};

//2.利用大根堆(priority_queue<int>)
//先将数组前k个数放进大根堆
//再依次对n-k个数和maxHeap.top()比较, 小于top则替换
//执行完后大根堆中存放的即为最小的k个数
//时间复杂度 N*logk 空间复杂度 logk
// class Solution {
// public:
//     vector<int> getLeastNumbers(vector<int>& arr, int k) {
//         if(arr.empty() || k == 0) return vector<int>(0);
//         priority_queue<int> maxHeap;
//         for(int i = 0; i< k; i++) maxHeap.push(arr[i]);
//         for(int i = k; i < arr.size(); ++i){
//             if(arr[i] < maxHeap.top()){
//                 maxHeap.pop();
//                 maxHeap.push(arr[i]);
//             }
//         }
//         vector<int> rst(k);
//         for(int i = 0; i < k; ++i){
//             rst[i] = maxHeap.top();
//             maxHeap.pop();
//         }
//         return rst;
//     }
// };
