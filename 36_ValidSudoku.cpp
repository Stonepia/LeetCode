#include <vector>

using namespace std;

/***************************************/
// Slow Version
class Solution
{
  public:
    bool isNum(char c)
    {
        return c >= '0' && c <= '9';
    }
    bool validLine(vector<vector<char>> &board, int startPoint, bool isRow)
    {
        vector<bool> hashMap(10, false);
        if (isRow)
        {
            for (int i = 0; i < 9; ++i)
            {
                if (isNum(board[startPoint][i]) &&
                    (hashMap.at(board[startPoint][i] - '0') == false))
                    hashMap.at(board[startPoint][i] - '0') = true;
                else if (board[startPoint][i] == '.')
                    continue;
                else
                    return false;
            }
        }
        else
        {
            for (int i = 0; i < 9; ++i)
            {
                if (isNum(board[i][startPoint]) &&
                    (hashMap.at(board[i][startPoint] - '0') == false))
                    hashMap.at(board[i][startPoint] - '0') = true;
                else if (board[i][startPoint] == '.')
                    continue;
                else
                    return false;
            }
        }

        return true;
    }
    bool validBoard(vector<vector<char>> &board, int leftUpRow, int leftUpCol)
    {
        vector<bool> hashMap(10, false);
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (isNum(board[leftUpRow + i][leftUpCol + j]) &&
                    (hashMap.at(board[leftUpRow + i][leftUpCol + j] - '0') == false))
                    hashMap.at(board[leftUpRow + i][leftUpCol + j] - '0') = true;
                else if (board[leftUpRow + i][leftUpCol + j] == '.')
                    continue;
                else
                    return false;
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool res = true;
        for (int i = 0; i < 9; ++i)
        {
            res &= validLine(board, i, true);
            res &= validLine(board, i, false);
        }
        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
                res &= validBoard(board, i, j);
        }
        return res;
    }
};

// Very Clever Version !!!
// Using Bitwise Operation
// From @lchen77
// https://leetcode.com/problems/valid-sudoku/discuss/15452/C%2B%2B-very-simple-and-easy-understand.-using-bit-operation

class Solution
{
  public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<int> col(9, 0);
        vector<int> block(9, 0);
        vector<int> row(9, 0);
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    int indx = 1 << (board[i][j] - '0');
                    if (row[i] & indx ||
                        col[j] & indx ||
                        block[i / 3 * 3 + j / 3] & indx)
                        return false;
                    row[i] |= indx;
                    col[j] |= indx;
                    block[i / 3 * 3 + j / 3] |= indx;
                }
            }
        return true;
    }
};