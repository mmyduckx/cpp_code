/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //1.双栈法
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         stack<TreeNode* > s1,s2;
//         vector<vector<int>> rst;
//         if(root == nullptr) return rst;
//         s1.push(root);
//         while(!s1.empty() || !s2.empty()){
//             vector<int> v;
//             while(!s1.empty()){
//                 TreeNode* top = s1.top();
//                 v.push_back(top->val);
//                 s1.pop();
//                 if(top->left) s2.push(top->left);
//                 if(top->right) s2.push(top->right);
//             }
//             if(!v.empty()) rst.push_back(v);
//             v.clear();
//             while(!s2.empty()){
//                 TreeNode* top = s2.top();
//                 v.push_back(top->val);
//                 s2.pop();
//                 if(top->right) s1.push(top->right);
//                 if(top->left) s1.push(top->left);
//             }
//             if(!v.empty()) rst.push_back(v);
//         }
//         return rst;
//     }
// };

//2.deque
// 前进前出,后进后出
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<TreeNode*> Deq;
        vector<vector<int>> rst;
        if(root == nullptr) return rst;
        Deq.push_front(root);
        bool reverse = false;  
        while(!Deq.empty()){
            int n = Deq.size();
            vector<int> v;
            if(reverse == false){ //从队首正向访问,依次将左右子树放到队尾
                while(n){
                    TreeNode* front = Deq.front();
                    v.push_back(front->val);
                    Deq.pop_front();
                    if(front->left) Deq.push_back(front->left);
                    if(front->right) Deq.push_back(front->right);
                    --n;
                    }
            }
            else{ //从队尾逆向访问,依次将右左子树放到队首
                while(n){
                    TreeNode* back = Deq.back();
                    v.push_back(back->val);
                    Deq.pop_back();
                    if(back->right) Deq.push_front(back->right);
                    if(back->left) Deq.push_front(back->left);
                    --n;
                }
            }
            rst.push_back(v);
            reverse = !reverse;
        }
        return rst;
    }
};
