#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums,int target) {
        sort(nums.begin(),nums.end());
       // vector<vector<int> > res;
        int l=0;
        int r=0;
        int sum=0;
        int margin=INT_MAX;
        int res1=res2=res3=0;
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1])
                continue;
            l=i+1;
            r=nums.size()-1;
            while(l<r){
                sum=nums[i]+nums[l]+nums[r];
                if(sum>target) r--;
                else if(sum<target) l++;
                else return vector<int> {nums[i],nums[l],nums[r]}; 
            }
            if(abs(sum-target)<margin){
                margin=abs(sum-target);
                res1=i;
                res2=l;
                res3=r;
            }
        }
    return vector<int> {nums[i],nums[l],nums[r]};
    }
};