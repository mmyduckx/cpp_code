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
    vector<int> reversePrint(ListNode* head) {
        int count = 0;
        ListNode* p = head;
        while(p){
            ++count;
            p = p->next;
        }
        p = head;
        vector<int> rst(count);
        for(auto it = rst.rbegin(); it != rst.rend(); ++it){
            *it = p->val;
            p = p->next;
        }
        return rst;
    }
};
