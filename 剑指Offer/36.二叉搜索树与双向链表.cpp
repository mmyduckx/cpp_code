/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
//思路:中序遍历 左根右
class Solution {
public:
    Node* pre = nullptr;
    Node* head = nullptr;
    void dfs(Node* root){
        if(root == nullptr) return;
        dfs(root->left);
        //do something
        if(pre != nullptr) pre->right = root;
        else head = root;
        root->left = pre;
        pre = root;
        dfs(root->right);
    }
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return nullptr;
        dfs(root);
        Node* tail = head;
        while(tail->right){
            tail = tail->right;
        }
        tail->right = head;
        head->left = tail;
        return head;
    }
};
