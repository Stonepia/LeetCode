#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        int target_restore = -target;
        auto beg = nums.begin();
        auto end = nums.end() - 1;
        for (beg; *beg <= 0;++beg)
        {
            for (end; *end >= 0; --end)
            {
                temp.clear();
                target = target_restore;
                cout << "target is " << target << endl;
                target += *beg;
                temp.push_back(*beg);
                if (checkSum(beg, end, target, 3, temp) == true)
                {
                    sort(temp.begin(), temp.end());
                    result.push_back(temp);
                }

            }
        }
        return result;
    }

    bool checkSum(
        vector<int>::iterator beg, vector<int>::iterator end,
        int target, int count, vector<int> &temp)
    {

        if (count == 1 && (beg != end))
        {
            auto t = find(beg, end + 1, -target);
            if (t != end + 1)
            {
                temp.push_back(*t);
                return true;
            }
            else
                return false;
        }
        if (target <= 0 && beg != end)
        {
            target += *end;
            temp.push_back(*end);
            end--;
            count--;
            return checkSum(beg, end, target, count, temp);
        }
        else if (target > 0 && beg != end)
        {
            target += *beg;
            temp.push_back(*beg);
            beg++;
            count--;
            return checkSum(beg, end, target, count, temp);
        }
        return false;
    }
};