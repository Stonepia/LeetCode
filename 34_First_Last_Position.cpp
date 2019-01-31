#include <vector>
#include <algorithm>
using namespace std;

/************************************/
// Cheat Solution
class Solution
{
  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        auto bounds = equal_range(nums.begin(), nums.end(), target);
        vector<int> res{-1, -1};
        if (bounds.second - bounds.first != 0)
        {
            res.at(0) = bounds.first - nums.begin();
            res.at(1) = bounds.second - nums.begin() - 1;
        }
        return res;
    }
};

// Native Solution

class Solution
{
  public:
    int get_bound(vector<int> &nums, int target, bool left = true)
    {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo < hi)
        {
            int mid = (hi - lo) >> 1 + lo;
            if (nums.at(mid) > target || (left && target == nums.at(mid)))
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return lo;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res{-1, -1};
        if (nums.empty())
            return res;

        int left = get_bound(nums, target, true);
        int right = get_bound(nums, target, false);

        if (left == nums.size() || nums.at(left) != target)
            return res;

        res.at(0) = left;
        res.at(1) = right - 1;
        return res;
    }
};