#include "CommonHeader.h"

class Solution
{
  public:
    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size();
        wordsz = word.size();
        if (m == 0 && wordsz != 0)
            return false;
        if (wordsz == 0 || (m == 0 && wordsz == 0))
            return true;
        n = board.at(0).size();

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (exist(board, word, i, j, 0, ))
                    return true;
            }
        return false;
    }

  private:
    int m;
    int n;
    int wordsz;
    bool exist(vector<vector<char>> &board, string word, int row, int col, int start)
    {
        char curC = board.at(row).at(col);
        if(curC!=word.at(start))
            return false;
        if(start==wordsz-1)
            return true;
        board.at(row).at(col) = '*';
        bool res=false;
        if(row>0)
            res = exist(board, word, row - 1, col, start + 1);
        if(!res&& row<m-1)
            res = exist(board, word, row + 1, col, start + 1);
        if(!res&&col>0)
            res = exist(board, word, row  , col-1, start + 1);
        if(!res&& col<n-1)
            res = exist(board, word, row, col+1, start + 1);
        board.at(row).at(col) = curC;
        return res;
    }
};