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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1=l1;
        ListNode *p2=l2;
        ListNode *res=new ListNode(0);
        ListNode *p3=res;
        int carryNum=0;

        while(p1!=NULL||p2!=NULL){
            if(p1!=NULL)
            {
                carryNum+=p1->val;
                p1=p1->next;
            }
            if(p2!=NULL)
            {
                carryNum+=p2->val;
                p2=p2->next;
            }
           
            p3->next = new ListNode(carryNum%10);
            p3=p3->next;
            carryNum/=10;
        }
        if(carryNum==1)
            p3->next=new ListNode(carryNum);
        return res->next;
    }
};