#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    void cobSumAux(vector<int> &candidates, int target,
                   vector<vector<int>> &res, vector<int> &tempV, int index)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            res.push_back(tempV);
            return;
        }

        while (index < candidates.size() and target - candidates.at(index) >= 0)
        {

            tempV.push_back(candidates.at(index));
            cobSumAux(candidates, target - candidates.at(index), res, tempV, index + 1);
            while ((index + 1 < candidates.size()) and tempV.back() == candidates.at(index + 1))
                ++index;
            tempV.pop_back();
            ++index;
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tempV;
        cobSumAux(candidates, target, res, tempV, 0);
        return res;
    }
};