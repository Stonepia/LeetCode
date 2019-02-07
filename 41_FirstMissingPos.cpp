#include <vector>
#include <algorithm>
using namespace std;

//WRONG ANSWER
// Because of the Sort, TIME COMPLEXITY is O(nlgn)
class Solution
{
  public:
    int firstMissingPositive(vector<int> &nums)
    {
        if (nums.empty())
            return 1;
        sort(nums.begin(), nums.end());
        auto it = nums.begin();
        while (it != nums.end() && *it < 0)
            it++;
        if ((*it) >= 2)
            return 1;
        int pre = *it;
        it++;
        while (it != nums.end())
        {
            while (*it == pre)
                it++;
            if (*it != pre + 1)
                return pre + 1;
            else
            {
                pre = *it;
                it++;
            }
        }
        return pre + 1;
    }
};

// Correct One
class Solution
{
  public:
    int firstMissingPositive(vector<int> &nums)
    {
        if (nums.empty())
            return 1;
        int len = nums.size();
        int end = len - 1;
        int beg = 0;
        for (beg; beg < len; ++beg)
        {
            while (nums.at(beg) > 0 && nums.at(beg) <= len && nums.at(beg) != nums.at(nums.at(beg) - 1))
                swap(nums.at(nums.at(beg) - 1), nums.at(beg));
        }
        for (int i = 0; i < len; ++i)
            if (nums.at(i) != i + 1)
                return i + 1;
        return len + 1;
    }
};