#include "CommonHeader.h"

// Classic DP Problem
//   dp[i][j] is the Minimum Edit Distance from word1[i] to word2[j]
//              0, i==0,j==0
//  dp[i][j]=   dp[i-1][j-1]+1  ,  word1[i]=word2[j]
//              min(dp[i-1][j],dp[i][j-1], dp[i-1][j-1])+1,  word1[i]!=word2[j]
//                   ^Add Or Delete            ^ Replace
class Solution
{
  public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        if (m == 0)
            return n;
        if (n == 0)
            return m;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
            dp.at(i).at(0) = 1;
        for (int j = 0; j < n; ++j)
            dp.at(0).at(j) = 1;

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
            {
                if(word1.at(i)==word2.at(j))
                    dp.at(i).at(j) = dp.at(i - 1).at(j - 1) + 1;
                else
                {
                    // Notice if we 
                    dp.at(i).at(j) = min(min(dp.at(i - 1).at(j), dp.at(i).at(j - 1)),dp.at(i-1).at(j-1)) + 1;
                }
                
            }
        return dp.at(m - 1).at(n - 1);
    }
};