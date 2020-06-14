/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//思路
 //BFS
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> rst;
        queue<TreeNode*> q;
        if(root == nullptr) return rst;
        else{
            q.push(root);
            while(!q.empty()){
                TreeNode* front = q.front();
                q.pop();
                rst.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            return rst;
        }
    }
};
