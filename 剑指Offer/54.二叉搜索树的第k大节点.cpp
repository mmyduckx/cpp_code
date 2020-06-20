/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //思路: 注意BST特性 左<= 根 < 右
 //中序遍历 右根左 时间复杂度logn
// class Solution {
// public:
//     int rst;
//     void helper(TreeNode* root, int& k){
//         if(root == nullptr) return;
//         helper(root->right, k);
//         if(--k == 0) {
//             rst = root->val;
//             return;
//         }
//         helper(root->left, k);
//         return;
//     }

//     int kthLargest(TreeNode* root, int k) {
//         helper(root, k);
//         return rst;
//     }   
// };

//非递归实现
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        int count = 0;
        //右 根 左
        while(!s.empty() || root != nullptr){
            while(root != nullptr){
                s.push(root);
                root = root->right;
            }
            //根
            root = s.top();
            s.pop();
            if(++count == k) return root->val;
            // 左
            root = root->left;
        }
    return 0;
    }
};
