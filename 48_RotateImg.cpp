#include <vector>
using namespace std;

/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        if(len < 2)
            return;
        int mid = len / 2;
        for (int i = 0; i < mid;++i){
            swap(matrix.at(i), matrix.at(len-i-1));
        }
        for (int i = 1; i < len;++i)
            for (int j = 0; j < i;++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        
    }
};