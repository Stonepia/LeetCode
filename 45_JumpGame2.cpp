#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

// Naive DP Solution
// O(n^2), Will Easily Get Time Exceeded!
class Solution
{
  public:

    int jump(vector<int> &nums)
    {
        int len = nums.size();
        if (len <= 1)
            return 0;
        vector<int> dp(len, INT_MAX);
        dp.at(len - 1) = 0;
        for (int i = len - 2; i >= 0; --i)
        {

            int temp = INT_MAX - 1;
            for (int j = nums.at(i); j > 0; --j)
            {
                int index = min(i + j, len - 1);
                temp = min(dp.at(index), temp);
            }
            dp.at(i) = temp + 1;
        }
        return dp.at(0);
    }
};



// Another Version
class Solution
{
  public:
    int jump(vector<int> &nums)
    {
        int maxReachPreviousJump = -1, maxReachCurrentJump = 0, jumps = 0;
        for (int i = 0; i < nums.size();++i){
            if(maxReachCurrentJump >=nums.size() -1)
                return jumps;
            if(i > maxReachPreviousJump)
            {
                ++jumps;
                maxReachPreviousJump = maxReachCurrentJump;
            }
            maxReachCurrentJump = max(maxReachCurrentJump, i + nums.at(i));
        }
        return jumps;
    }
};


// O(n) Solution
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if(len <=1)
            return 0;
        deque<pair<int, int>> dq;
        dq.push_back(make_pair(0, nums.at(0)));
        for (int i = 1; i < len;++i){
            if(dq.front().second < i)
                dq.pop_front();
            int r = i + nums.at(i);
            if(r>dq.back().second)
                dq.push_back(make_pair(dq.front().first + 1, r));

        }
        return 1 + dq.front().first;
    }
};
