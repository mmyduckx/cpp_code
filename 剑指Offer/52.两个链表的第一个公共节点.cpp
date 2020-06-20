/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //思路:分别从A和B出发,当各自走到链表尾部时与对方的头部相接,最终总会相遇在焦点处
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while(p1 != p2){
            if(p1 != nullptr) p1 = p1->next;
            else p1 = headB;
            if(p2 != nullptr) p2 = p2->next;
            else p2 = headA;
        }
        return p1;
    }
};
