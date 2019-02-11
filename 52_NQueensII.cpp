#include <vector>
#include <string>
using namespace std;


// Native Solution
class Solution
{
  public:
    int totalNQueens(int n)
    {
        vector<string> nQueens(n, string(n, '.'));
        solveNQueens(nQueens, 0, n);
        return count;
    }

  private:
    int count;
    void solveNQueens(vector<string> &nQueens,
                      int row, int n)
    {
        if (row == n)
        {
            count++;
            return;
        }
        for (int col = 0; col != n; ++col)
        {
            if (isValid(nQueens, row, col, n))
            {
                nQueens[row][col] = 'Q';
                solveNQueens(nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
        }
    }
    bool isValid(vector<string> &nQueens, int row, int col, int n)
    {
        for (int i = 0; i != row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;
        // Check Diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >=0; --i, --j)
            if (nQueens[i][j] == 'Q')
                return false;
        return true;
    }
};

// Using BitWise Operations:
// https://leetcode.com/problems/n-queens-ii/discuss/20094/A-classic-C-solution-using-bitwise-operations-(0ms)
class Solution {
public:
    int next(int row, unsigned int vertMask, unsigned int leftMask, unsigned int rightMask, unsigned rangeMask){
        if (row ==0)
            return 1;
        unsigned int mask = rangeMask & ~(leftMask | rightMask | vertMask);
        int r = 0;
        while(mask){
            unsigned int queenflag = mask & -mask; // Get the Lowest 1-bit
            r += next(row - 1,
                      (vertMask | queenflag),
                      (leftMask | queenflag) << 1,
                      (rightMask | queenflag) >> 1,
                      rangeMask);
            mask ^= queenflag;
        }
        return r;
    }
    int totalNQueens(int n) {
        return next(n, 0, 0, 0, ((unsigned int)-1) >> (32-n));
    }
};