#include <algorithm>
#include <vector>
using namespace std;

// Solution Similar to Problem 31:
// https://leetcode.com/problems/next-permutation/
class Solution
{
  public:
    void next_permutation(vector<vector<int>> &res, vector<int> &nums)
    {

        auto dest = std::is_sorted_until(nums.rbegin(), nums.rend());
        if (dest != nums.rend())
        {
            auto target = std::upper_bound(nums.rbegin(), dest, *dest);
            std::iter_swap(dest, target);
        }
        std::reverse(nums.rbegin(), dest);
        res.push_back(nums);
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.empty())
            return res;
        int sz = nums.size();
        int count = 1;
        for (sz; sz > 0; --sz)
            count *= sz;

        for (count; count > 0; --count)
            next_permutation(res, nums);

        return res;
    }
};

// An Easy to UnderStand Version
// O(n^2)
// https://leetcode.com/problems/permutations/discuss/18247/My-elegant-recursive-C%2B%2B-solution-with-inline-explanation
class Solution
{
  public:
    void permuteRecursive(vector<int> &nums, int beg, vector<vector<int>> &res)
    {
        if(beg>= nums.size())
            {
                res.push_back(nums);
                return;
            }
            for (int i = beg; i < nums.size();++i){
                swap(nums.at(beg), nums.at(i));
                permuteRecursive(nums, beg + 1, res);
                swap(nums.at(beg), nums.at(i));
            }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        permuteRecursive(num, 0, res);
        return res;
    }
};

