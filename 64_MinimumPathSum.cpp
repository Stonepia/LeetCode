#include "CommonHeader.h"

class Solution
{
  public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid.at(0).size();
        // dp[i][j] represents the shortest path to [i][j]
        vector<vector<long>> dp(m, vector<long>(n, 0));
        dp.at(0).at(0) = grid.at(0).at(0);
        for (int j = 1; j < n; ++j)
        {
            dp.at(0).at(j) = dp.at(0).at(j - 1) + grid.at(0).at(j);
        }
        for (int i = 1; i < m; ++i)
        {
            dp.at(i).at(0) = dp.at(i-1).at(0) + grid.at(i).at(0);
        }

        for (int i = 1; i < m;++i)
            for (int j = 1; j < n;++j){
                dp.at(i).at(j) = min(dp.at(i - 1).at(j), dp.at(i).at(j - 1)) + grid.at(i).at(j);
            }

        return (int)dp.at(m - 1).at(n - 1);
    }
};