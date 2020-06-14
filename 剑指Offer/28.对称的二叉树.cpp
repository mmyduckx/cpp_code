/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//1.递归
//利用core每次交替比较左右子树
// class Solution {
// public:
//     bool isSymmetricCore(TreeNode* l, TreeNode* r){
//         if(l == nullptr && r == nullptr) return true;
//         if(l == nullptr || r == nullptr) return false;
//         return (l->val == r->val) && isSymmetricCore(l->left, r->right) && isSymmetricCore(l->right, r->left);
//     }

//     bool isSymmetric(TreeNode* root) {
//         if(root == nullptr) return true;
//         return isSymmetricCore(root->left, root->right);
//     }
// };

//2.迭代
//使用队列:每次推入lchild的的左子树 rchild的右子树 和lchild的右子树和rchild的左子树
//注意: 当左右子树都为空时不能立刻返回true. 因为可能还有其他子树没判断,所以要用continue
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        queue<TreeNode*> Q;
        Q.push(root->left);
        Q.push(root->right);
        while(!Q.empty()){
            TreeNode* l = Q.front();
            Q.pop();
            TreeNode* r = Q.front();
            Q.pop();
            if(l == nullptr && r == nullptr) continue;
            if(l == nullptr || r == nullptr) return false;
            if(l->val != r->val) return false;
            Q.push(l->left);
            Q.push(r->right);
            Q.push(l->right);
            Q.push(r->left);
        }
        return true;
    }
};
