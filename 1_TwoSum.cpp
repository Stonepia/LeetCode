class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<size_t,size_t>myMap;
        for(int i=0;i<nums.size();++i)
            myMap[nums[i]]=i;
        vector<int> result;
        for(int i=0;i<nums.size();++i)
        {
            int rest_val=target-nums[i];
           // pair<size_t,size_t> res;
            auto res = myMap.find(rest_val);
            if(res!=myMap.end())
           { 
                result.push_back(i);
                result.push_back(res->second);
                return result;
            }

        }
    throw new IllegalArgumentException("No two sum solution");
    }
};