/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //思路:
 //快慢指针 p1先走k步 然后p1,p2一起走到p1为空时p2走了n-k步
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head == nullptr) return nullptr;

        ListNode* p1 = head;
        ListNode* p2 = head;
        while(k){
            p1 = p1->next;
            --k;
        }
        while(p1){
            p1 = p1->next;
            p2 = p2->next;
        }

        return p2;
    }
};
