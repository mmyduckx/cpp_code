/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//1.利用两个队列,交替存左右节点实现
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> rst;
//         if(root == nullptr) return rst;
//         queue<TreeNode*> q1,q2;
//         q1.push(root);
//         while(!q1.empty() || !q2.empty()){
//             vector<int> v;
//             while(!q1.empty()){
//                 TreeNode* front = q1.front();
//                 v.push_back(front->val);
//                 q1.pop();
//                 if(front->left) q2.push(front->left);
//                 if(front->right) q2.push(front->right);
//             }
//             if(!v.empty()) rst.push_back(v);
//             v.clear();
//             while(!q2.empty()){
//                 TreeNode* front = q2.front();
//                 v.push_back(front->val);
//                 q2.pop();
//                 if(front->left) q1.push(front->left);
//                 if(front->right) q1.push(front->right);
//             }
//             if(!v.empty()) rst.push_back(v);
//         }
//         return rst;
//     }
// };

//2.利用单队列BFS
//记得每次记录Queue的大小,并循环q.size()次
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> rst;
        if(root == nullptr) return rst;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> v;
            while(n>0){
                TreeNode* front = q.front();
                q.pop();
                v.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                --n;
            }
            if(!v.empty()) {
                rst.push_back(v);
            }
        }
        return rst;
    }
};
