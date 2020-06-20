/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //1.DFS后续递归求解 每层深度=max(左子树深度,右子树深度)+1 时间复杂度N 空间复杂度N
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root == nullptr) return 0;
//         return max(maxDepth(root->left), maxDepth(root->right)) + 1;
//     }
// };
//2.利用队列 层级BFS遍历求解 时间复杂度N 空间复杂度N
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> q;
        int rst = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size){
                TreeNode* front = q.front();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                q.pop();
                --size;
            }
            ++rst;
        }
        return rst;
    }
};
