//思路:
//检查是否时后序遍历即要检查是否满足[左|右|根]的规律
//在BST中,递归条件在于左<根<右(本题条件不重复)
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.empty()) return true;
        //先找左右子树分界处index
        int root = postorder[postorder.size()-1];
        int index = 0;
        for(int i = 0; i < postorder.size() - 1; ++i){
            if(postorder[i] < root){
                ++index;
            }
            else{ //find split index
                break;
            }
        }
        //找右子树有没有不满足条件的
        for(int i = index; i < postorder.size() - 1; ++i){
            if(postorder[i] < root) return false;
        }
        bool left = true;
        //当左子树存在时,对左子树递归
        if(index > 0){
            vector<int> l_postorder(postorder.begin(), postorder.begin() + index);
            left = verifyPostorder(l_postorder);
        }
        bool right = true;
        //当右子树存在时,对右子树递归
        if(index < postorder.size() - 1){
            vector<int> r_postorder(postorder.begin() + index, postorder.end() - 1);
            right = verifyPostorder(r_postorder);
        }
        return left&&right;
    }
};
