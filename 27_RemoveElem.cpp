#include <vector>
using std::vector;

/*************************/

// Slow version
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       if(nums.empty())
           return 0;
       size_t sz = nums.size();
       int beg = -1;
       size_t end = 0;
       while(end < sz){
           if(nums[end]!=val)
           {
               beg++;
               nums[beg] = nums[end];
           }
           end++;
       }
       return beg + 1;
    }
};

// Fast version
// From back to front
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())
            return 0;
        size_t sz = nums.size();
        size_t end = sz;
        size_t beg = 0;

        while(beg < end){
            if(nums[beg]==val){
                nums[beg] = nums[end-1];
                end--;
            }
            else
                beg++;
        }
        return end;
    }
};