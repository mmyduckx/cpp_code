/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* p = head;
        if(p->val == val){
            head = head->next;
            return head;
        }
        else{
            while(p->next){
                if(p->next->val == val){
                    p->next = p->next->next;
                    return head;
                }
                p = p->next;
            }
        }
        return head;
    }
};
