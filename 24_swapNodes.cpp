struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void swap(ListNode * p, ListNode * q, ListNode * pre){
        p->next = q->next;
        q->next = pre->next;
        pre->next = q;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode *pre = new ListNode(-1);//header
       
        pre->next = head;
        ListNode *p = head;
        if(p==nullptr)
            return p;
        ListNode *q = head->next;
        if(q==nullptr)
            return p;

        ListNode *res = pre;
        while(p && q)
        {
            swap(p, q,pre);
            if(p->next && p->next->next)
                {
                    pre = p;
                    p = p->next;
                    q = p->next;
                }
            else
                break;
        }
        return res->next;
    }
};