#include <vector>

using namespace std;

/**********************************/
// Trivial Solution
class Solution
{
  public:
    int find_rotate_index(const vector<int> &nums)
    {

        int len = nums.size();
        if (len == 1)
            return 0;

        int left = 0;
        int right = len - 1;

        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if ((mid == len - 1) || nums.at(mid) > nums.at(mid + 1))
                return mid;
            else if (nums.at(mid) < nums.at(left))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return 0;
    }
    int search(vector<int> &nums, int target, int left, int right)
    {
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums.at(mid) == target)
                return mid;
            else if (nums.at(mid) > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return -1;
        // Pivot index
        int pindex = find_rotate_index(nums);

        int len = nums.size();
        if (target == nums.at(pindex))
        {
            return pindex;
        }

        // Search the right part
        if (target < nums.at(0))
            return search(nums, target, pindex + 1, len - 1);
        // Search the left part
        return search(nums, target, 0, pindex);
    }
};

