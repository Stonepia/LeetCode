#include "CommonHeader.h"

class Solution
{
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty()||matrix.at(0).empty())
            return false;
        int m = matrix.size();
        int n = matrix.at(0).size();
        int low = 0, high = m * n - 1;
        while (low < high)
        {
             int mid = (low +high - 1) >> 1;
            if (matrix.at(mid / n).at(mid % n) < target)
                low = mid + 1;
            else if(matrix.at(mid/n).at(mid%n)==target)
                return true;
            else
                high = mid;
        }
        return matrix.at(high / n).at(high % n) == target;
    }
};