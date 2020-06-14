/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //思路:当root不为空 交换左右节点,再递归对左右节点进行交换
class Solution {
public:

    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        else swap(root->left, root->right);
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};
