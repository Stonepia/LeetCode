#include <vector>
using namespace std;

// The Naive Solution
class Solution
{
  public:
    void auxSpiralOrder(vector<vector<int>> &matrix, vector<int> &res,
                        int rowBeg, int rowEnd,
                        int colBeg, int colEnd,
                        int flag)
    {
        if (rowBeg >= rowEnd || colBeg >= colEnd)
            return;
        switch (flag)
        {
        case 0: // Row From Left to Right
        {
            for (int i = colBeg; i != colEnd; ++i)
            {
                res.push_back(matrix[rowBeg][i]);
            }
            rowBeg++;
            break;
        }
        case 1: // Col From Up to Bottom
        {
            for (int i = rowBeg; i != rowEnd; ++i)
            {
                res.push_back(matrix[i][colEnd - 1]);
            }
            colEnd--;
            break;
        }
        case 2: //Row From Right to Left
        {
            for (int i = colEnd - 1; i >= colBeg; --i)
            {
                res.push_back(matrix[rowEnd - 1][i]);
            }
            rowEnd--;
            break;
        }
        case 3: // Col From Bot To Up
        {

            for (int i = rowEnd - 1; i >= rowBeg; --i)
            {
                res.push_back(matrix[i][colBeg]);
            }
            colBeg++;
            break;
        }
        default:
            break;
        }
        flag = (flag + 1) % 4;
        auxSpiralOrder(matrix, res,
                       rowBeg, rowEnd, colBeg, colEnd, flag);
    }
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        if (matrix.empty())
            return res;
        auxSpiralOrder(matrix, res, 0, matrix.size(), 0, matrix[0].size(), 0);
        return res;
    }
};

// Simplified Version
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> res;
	if (matrix.empty())
		return res;
	int rLen = matrix.size();
	int cLen = matrix.at(0).size();

	int rBeg = 0, cBeg = 0, rEnd = rLen-1, cEnd = cLen-1;
	while (rBeg <= rEnd && cBeg <= cEnd) {
		for (int j = cBeg; j <= cEnd; ++j)
			res.push_back(matrix[rBeg][j]);
		for (int i = rBeg + 1; i <= rEnd; ++i)
			res.push_back(matrix[i][cEnd]);
		if (rBeg < rEnd&& cBeg < cEnd)
		{
			for (int j = cEnd - 1; j > cBeg; --j)
				res.push_back(matrix[rEnd][j]);

			for (int i = rEnd; i > rBeg; --i)
				res.push_back(matrix[i][cBeg]);
		}
		rBeg++;
		cBeg++;
		rEnd--;
		cEnd--;
	}
	return res;
}