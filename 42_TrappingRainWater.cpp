#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    int trap(vector<int> &height)
    {
        if (height.empty())
            return 0;
        int len = height.size();
        int res = 0;
        vector<int> left_max(len), right_max(len);
        left_max[0] = height[0];
        for (int i = 1; i < len;++i){
            left_max.at(i) = max(height.at(i), left_max.at(i - 1));
        }
        right_max.at(len - 1) = height.at(len - 1);
        for (int i = len - 2; i >= 0;--i)
            right_max.at(i) = max(height.at(i), right_max.at(i + 1));

        for (int i = 1; i < len - 1;++i)
            res += min(left_max.at(i), right_max.at(i)) - height.at(i);
        return res;
    }
};

