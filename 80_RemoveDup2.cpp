#include "CommonHeader.h"

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        int sz = nums.size(), count = 0;
        for (int i = 2; i < sz; ++i)
            if (nums.at(i) == nums.at(i - 2 - count))
                count++;
            else
                nums.at(i - count) = nums.at(i);
        return sz - count;
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int n:nums)
            if(i<2||n!=nums.at(i-2))
                nums.at(i++) = n;
        return i;
    }
};