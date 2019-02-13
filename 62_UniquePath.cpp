#include "CommonHeader.h"

// Math Solution
// Just a Permutation problem
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 and n==1)
            return 1;
        m--;
        n--;
        if(m<n)
            swap(m, n);
        int res=1;
        int j = 1;
        for (int i = m + 1; i <= m + n;++i,++j){
            res *= i;
            res /= j;
        }
        return res;
    }
};
// Dynamic Programming

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> map(m, vector<int>(n, 0));
        for(int i = 0; i < m;++i)
            map[i][0] = 1;
        for(int j = 0; j < n;++j)
            map[0][j] = 1;

        for(int i = 1; i < m;++i)
            for (int j = 1; j < n;++j)
                map[i][j] = map[i - 1][j] + map[i][j - 1];

        return map[m - 1][n - 1];
    }
};