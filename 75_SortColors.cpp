#include "CommonHeader.h"

// Very typical Dutch Flag Problem
// Red, White, Blue
class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        if (nums.empty())
            return;
        int sz = nums.size();
        int redInd = 0;
        int blueInd = sz - 1;
        int cur = 0;
        while (cur <= blueInd)
        {
            if (nums.at(cur) == 0)
            {
                swap(nums.at(cur), nums.at(redInd));
                redInd++;
                cur++;
            }
            else if (nums.at(cur) == 2)
            {
                swap(nums.at(cur), nums.at(blueInd));
                blueInd--;
            }
            else
            {
                cur++;
            }
        }
    }
};