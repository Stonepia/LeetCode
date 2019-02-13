#include "CommonHeader.h"

// cheat solution
class Solution
{
  public:
    string getPermutation(int n, int k)
    {
        string res;
        for (int i = 1; i <= n; ++i)
            res.push_back('0' + i);
        cout << res << endl;
        while (--k)
        {

            next_permutation(res.begin(), res.end());
        }
        return res;
    }
};

// Optimized Solution
class Solution
{
  public:
    string getPermutation(int n, int k)
    {
        string res;
        string nums = "123456789";
        vector<int> factorial = {1, 1, 2, 6, 24, 120, 720, 5040,40320,362880 };
        --k;
        for (int i = n; i > 0;--i){
            int j = k / factorial[i - 1];
            k %= factorial[i - 1];
            res.push_back(nums[j]);
            nums.erase(nums.begin() + j);
        }
        return res;
    }
};