#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*********************************************/
#include <algorithm>
#include <queue> // Priority queue

// Approach 5: Divide and Conquer
class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        while (lists.size() > 1)
        {
            lists.push_back(mergeTwo(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    ListNode *mergeTwo(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        if (l1->val <= l2->val)
        {
            l1->next = mergeTwo(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwo(l1, l2->next);
            return l2;
        }
    }
};

// Approach 3 : Priority Queue
class Solution
{
  private:
    class Comp
    {
      public:
        bool operator()(ListNode *l1, ListNode *l2)
        {
            return l1->val > l2->val;
        }
    };

  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        priority_queue<ListNode *, vector<ListNode *>, Comp> que;
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        
        
        for (auto it : lists)
        {
            if (it)
                que.push(it);
        }
        if (que.empty())
            return nullptr;

        while (!que.empty())
        {
            ListNode *t = que.top();
            que.pop();
            cur->next = new ListNode(t->val);
            cur = cur->next;
            t = t->next;
            if(t)
                que.push(t);
        }
        return dummy->next;
    }
};
