#include "CommonHeader.h"
class Solution
{
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid.empty())
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid.at(0).size();
        // Table[i][j] represent how many paths to get to i,j
        vector<vector<long>> table(m, vector<long>(n, 0));
        int hasPath = 1;
        for (int j = 0; j < n; ++j)
        {
            if (obstacleGrid.at(0).at(j) == 1)
                hasPath = 0;
            table.at(0).at(j) = hasPath;
        }
        hasPath = 1;
        for (int i = 0; i < m; ++i)
        {
            if (obstacleGrid.at(i).at(0) == 1)
                hasPath = 0;
            table.at(i).at(0) = hasPath;
        }

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
            {
                if (obstacleGrid.at(i).at(j) == 1)
                    table.at(i).at(j) = 0;
                else
                    table.at(i).at(j) = table.at(i - 1).at(j) + table.at(i).at(j - 1);
            }

        return (int)table.at(m - 1).at(n - 1);
    }
};