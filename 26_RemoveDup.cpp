#include <vector>
using std::vector
/* *******  Original Solution  ****** */
class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        int sz = nums.size();
        if (sz == 0 || sz == 1)
            return sz;
        int beg = 0;
        int end = 1;
        while (1)
        {
            while (nums[beg] == nums[end] && end != sz - 1)
            {
                end++;
            }
            if(end!=sz-1){
                beg++;
                nums[beg] = nums[end];
                end++;
            }
            else if(nums[beg]!=nums[end]){
                beg++;
                nums[beg] = nums[end];
            }
            else break;
        }
        nums.resize(beg + 1);
        return beg+1;
    }
};


/************** Simplified Version ***************/
class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        if(nums.size() ==0) return 0;
        int i = 0;
        for (int j=1;j<nums.size();++j){
            if(nums[j] !=nums[i]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};

