#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// Approach 1 : DP
class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        int len = s.size();
        if (len == 0 || len == 1)
            return 0;
        vector<int> dp(len, 0);
        for (int i = 1; i < len; ++i)
        {
            if (s[i] == ')' && s[i - 1] == '(')
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;

            else if (s[i] == ')' && s[i - 1] == ')')
            {
                if ((i - dp[i - 1] > 0) && (s[i - dp[i - 1] - 1] == '('))
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
        }
        auto it = max_element(dp.begin(), dp.end());
        int res = *it;
        return res;
    }
};

// Approach 2 : Stack

#include <stack>

class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        if (s.empty())
            return 0;
        stack<int> st;
        int len = s.size();
        int maxlen = 0;

        st.push(-1);
        for (int i = 0; i < len; ++i)
        {
            if (s.at(i) == '(')
                st.push(i);
            else
            {
                st.pop();
                if (st.empty())
                    st.push(i);
                else
                {
                    maxlen = max(maxlen, i - st.top());
                }
            }
        }

        return maxlen;
    }
};

// Approach 3 : Left and Right Traverse
