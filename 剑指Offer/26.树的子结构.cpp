/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool Helper(TreeNode* A, TreeNode* B){
        if(B == nullptr) return true; //当B为空表示走完了,肯定是子树
        else if(A == nullptr) return false; //A走完了但B却没走完,肯定不是子树

        return (A->val == B->val) && Helper(A->left, B->left) && Helper(A->right, B->right); //当前节点值相同再比较左右子树

    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == nullptr || B == nullptr) return false;
        return Helper(A,B) || isSubStructure(A->left, B) || isSubStructure(A->right, B); //比较当前节点,不匹配再用A树左右节点比较
    }
};
