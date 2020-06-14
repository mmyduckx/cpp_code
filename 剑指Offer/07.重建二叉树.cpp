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
 //每次新建一个根节点,并递归建立左右子节点
 // 前序遍历 preorder = [1,2,4,7,3,5,6,8]
 // 中序遍历 inorder  = [4,7,2,1,5,3,8,6]
class Solution {
public:
    unordered_map<int, int> hashmap;    

    //start to end is the index range of each tree in inoreder[]
    TreeNode* build(int pre_index, int start_index, int end_index, vector<int> preorder){
        if(pre_index >= preorder.size() || start_index > end_index) return nullptr;
        int index = hashmap[preorder[pre_index]];

        TreeNode* root = new TreeNode(preorder[pre_index]);
        root->left = build(pre_index+1, start_index, index - 1, preorder);
        root->right = build(pre_index + (index-start_index) + 1, index+1, end_index, preorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;
        for(int i = 0; i < inorder.size(); ++i){
            hashmap[inorder[i]] = i;
        }
        TreeNode* root = build(0, 0, inorder.size() - 1, preorder);
        return root;
    }
};

