#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    void recursiveGet(vector<int> nums, int i, int j, vector<vector<int>> &res)
    {
        if (i == j - 1)
        {
            res.push_back(nums);
            return;
        }
        for (int k = i; k < j;++k){
            if(i !=k && nums.at(i)==nums.at(k))
                continue;
            swap(nums.at(i), nums.at(k));
            recursiveGet(nums, i + 1, j, res);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        recursiveGet(nums, 0, nums.size(), res);
        return res;
    }
};