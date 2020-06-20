/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //思路:1.打印路径非递归实现 T:O(n) S:O(n)
 //分别打印出根结点到p和q之间的路径。最后一个相同的点就是最近公共祖先。
 //思路:2.DFS递归 T:O(n) S:O(n)
 //分别对左右子树递归遍历,有以下几种情况
 //p和q在root的子树中，且分列root的异侧（即分别在左、右子树中）
 //p = root,且q在root的左或右子树中
 //q = root,且p在root的左或右子树中
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left == nullptr && right == nullptr) return nullptr;
        if(left == nullptr){
            return right;
        }
        if(right == nullptr){
            return left;
        }
        return root; //left != nullptr && right != nullptr
    }
};
