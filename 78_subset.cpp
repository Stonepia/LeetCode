#include "CommonHeader.h"

// Recursive
class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> subs{{}};
        for (int n : nums)
        {
            int sz = nums.size();
            for (int i = 0; i < sz; ++i)
            {
                subs.push_back(subs[i]);
                subs.back().push_back(n);
            }
        }
        return subs;
    }
};

// BackTracking
class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> sub;
        subsets(nums, res, sub, 0);
        return res;
    }

  private:
    void subsets(vector<int> &nums, vector<vector<int>> &res, vector<int> &sub, int start)
    {
        res.push_back(sub);
        for (int i = start; i < nums.size();++i){
            sub.push_back(nums.at(i));
            subsets(nums, res, sub, i + 1);
            sub.pop_back();
        }
    }
};