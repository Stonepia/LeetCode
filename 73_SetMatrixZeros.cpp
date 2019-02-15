#include "CommonHeader.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        int col0 = 1;
        int m = matrix.size();
        int n = matrix.at(0).size();

        for (int i = 0; i < m;++i)
        {
            if(matrix.at(i).at(0)==0)
                col0 = 0;
            for (int j = 1; j < n;++j){
                if(matrix.at(i).at(j)==0)
                    matrix.at(i).at(0) = matrix.at(0).at(j) = 0;
            }
        }

        for (int i = m - 1; i >= 0;--i)
        {
            for (int j = n - 1; j >= 1;--j)
            {
                if(matrix.at(i).at(0)==0 || matrix.at(0).at(j)==0)
                    matrix.at(i).at(j) = 0;
            }
            if(col0==0)
                matrix.at(i).at(0) = 0;
        }
    }
};