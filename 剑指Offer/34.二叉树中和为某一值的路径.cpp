/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //思路:利用DFS+回溯的思想
 //注意:
 //1.只有当该节点为叶子节点是才将路径推入最后的二维数组
 //2.可能存在负值节点,所以回溯时的判断条件要用等于和不等于来判断
class Solution {
public:
    vector<vector<int>> rst;
    vector<int> v;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return rst;
        if(root->left == nullptr && root->right == nullptr){ //是叶子节点,判断
            if(root->val == sum){ //符合,推入二维数组后要把当前值弹出数组,以便重复利用数组
                v.push_back(root->val);
                rst.push_back(v);
                v.pop_back();
            }
        }
        else{ //非叶子节点,不论值是否等于sum,继续往下走
            v.push_back(root->val);
            pathSum(root->left, sum - root->val);
            pathSum(root->right, sum - root->val);
            v.pop_back();
        }
        return rst;
    }
};
