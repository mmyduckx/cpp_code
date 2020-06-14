/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

//利用ostringstrem将int读入流 用空格隔开
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        ostringstream out;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front != nullptr){
                out << front->val << " ";
                q.push(front->left);
                q.push(front->right);
            }
            else out << "null ";
        }
        return out.str();
    }

//利用istringstrem将用空格分隔的string读出来, 转化为int
//先用vector存下new的结点,再把相应结点接起来
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream input(data);
        vector<TreeNode*> v;
        string str;
        while(input >> str){
            if(str == "null") v.push_back(nullptr);
            else v.push_back(new TreeNode(stoi(str)));
        }

        TreeNode* root;
        int j = 1;
        for(int i = 0; j < v.size(); ++i){
            if(v[i] == nullptr) continue;
            if(j < v.size()) v[i]->left = v[j++];
            if(j < v.size()) v[i]->right = v[j++];
        }
        return v[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
