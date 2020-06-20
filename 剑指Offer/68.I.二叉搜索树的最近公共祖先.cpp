/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //递归
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root->val > p->val && root->val > q->val){
//            return lowestCommonAncestor(root->left, p, q);
//        }
//         if(root->val < p->val && root->val < q->val){
//             return lowestCommonAncestor(root->right, p, q);
//         }
//         return root;
//     }
// };

//迭代
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root!= nullptr && (root != p || root != q)){
            if(root->val > p->val && root->val > q->val) root = root->left;
            else if(root->val < p->val && root->val <q->val) root = root->right;
            else break;
        }
        return root;
    }
};
