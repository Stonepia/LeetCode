#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    void cobSumAux(vector<int> &candidates, int target,vector<vector<int>> &res, vector<int> &subRes, int i)
    {
        if(target<0)
            return;
        if(target ==0)
        {
            res.push_back(subRes);
            return;
        }
        while(i<candidates.size() and target - candidates.at(i)>=0){

            subRes.push_back(candidates.at(i));
            cobSumAux(candidates, target - candidates.at(i), res, subRes, i);
            i++;
            subRes.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());


        vector<vector<int>> res;
        vector<int> subRes;

        cobSumAux(candidates, target, res, subRes, 0);
        return res;
    }
};