#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int l=0;
        int r=1;
        int i=2;
        int cursum=nums[i]+nums[l]+nums[r];
        int margin=INT_MAX;
        int sum;
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1])
                continue;
            l=i+1;
            r=nums.size()-1;
            while(l<r){
                cursum=nums[i]+nums[l]+nums[r];
                if(abs(cursum-target)<margin){
                    margin=abs(cursum-target);
                    sum=cursum;
                }         
                if(cursum>target) r--;
                else if(cursum<target) l++;
                else return cursum;
            }
        }  
    return sum;
    }
};
