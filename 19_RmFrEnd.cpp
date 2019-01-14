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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr) return nullptr;
        ListNode *p, *q;
        p = head;
        q = head;
        int sn=n;
        while(n--){
            q = q->next;
        }
        if(q==nullptr) return head->next;
        q=q->next;
        
        while(q!=nullptr){
            q = q->next;
            p = p->next;
        }
        if(sn==1) p->next = nullptr;
        else p->next=p->next->next;
       
        return head;
    }
};