struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/********************************************/
#include <vector>
#include <stack>
using std::stack;
using std::vector;

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == nullptr)
			return nullptr;
		ListNode *dummy = new ListNode(-1);
		stack<ListNode *> st;
		ListNode *pre = dummy;
		pre->next = head;
		ListNode *res = pre;

		int num = k;
		while ((num--) && head != nullptr) {
			st.push(head);
			head = head->next;
		}
		if (num >= 0)
			return res->next;
		ListNode *nt = st.top()->next; //Save for the last one
		while (!st.empty()) {
			pre->next = st.top();
			pre = pre->next;
			st.pop();
		}
		pre->next = nt;

		pre->next = reverseKGroup(pre->next, k);
		return res->next;

	}
};
