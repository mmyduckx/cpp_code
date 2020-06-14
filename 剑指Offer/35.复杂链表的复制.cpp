/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//1.利用哈希表映射,时间复杂度O(N),空间复杂度O(N)
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         unordered_map<Node*, Node*> hash;

//         for(Node* it = head; it; it = it->next){
//             hash[it] = new Node(it->val);
//         }
//         for(Node* it = head; it; it = it->next){
//             if(it->next) hash[it]->next = hash[it->next];
//             if(it->random) hash[it]->random = hash[it->random];
//         }
//         return hash[head];
//     }
// };

//2.利用线性迭代,原链表节点复制并插入
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node* p1 = head;
        Node* p2;
        while(p1){ //插入新节点
            p2 = p1->next;
            p1->next = new Node(p1->val);
            p1->next->next = p2;
            p1 = p2;
        }
        p1 = head;
        while(p1){
            p2 = p1->next;
            if(p1->random) p2->random = p1->random->next;
            else p2->random = nullptr;
            p1 = p2->next;
        }
        p1 = head;
        Node* head2 = head->next;
        while(p1){
            p2 = p1->next;
            p1->next = p2->next;
            p1 = p1->next;
            if(p2->next) p2->next = p2->next->next;
            p2 = p2->next;
        }
        return head2;
    }
};
