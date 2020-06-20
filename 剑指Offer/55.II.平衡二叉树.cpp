/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //思路: 平衡二叉树条件 -1 <= 左子树高度 - 右子树高度 <= 1

 //1.先序遍历 + 判断深度 （从顶至底）
 // 时间复杂度 == 每层执行复杂度×层数复杂度 = O(N×logN)
 // 空间复杂度 O(N)
// class Solution {
// public:
//     int height(TreeNode* root) {
//         if(root == nullptr) return 0;
//         return max(height(root->left), height(root->right)) + 1;
//     }

//     bool isBalanced(TreeNode* root) {
//         if(root == nullptr) return true;
//         return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
//     }
// };
//2.后序遍历 + 剪枝 （从底至顶）
//时间复杂度O(N):最差情况下，需要递归遍历树的所有节点。
//空间复杂度O(N):最差情况下（树退化为链表时），系统递归需要使用O(N)的栈空间。
class Solution {
public:
        int recur(TreeNode* root) {
            if(root == nullptr) return 0;
            int left = recur(root->left);
            if(left == -1) return -1; //一旦不平衡,做剪枝
            int right = recur(root->right);
            if(right == -1) return -1;  
            return abs(left - right) <= 1 ? max(left, right) + 1 : -1; //-1表示不平衡
        }

        bool isBalanced(TreeNode* root) {
            return recur(root) != -1;
    }
};
