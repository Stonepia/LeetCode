#include <vector>
#include <algorithm>
using namespace std;

// Simple Solution
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(len <=1)
            return true;
        bool res = false;
        //vector<int> maxReach(len, 0);
        int maxReach = 0;
        for(int i = 0; i < len;++i){
            if(maxReach<i)
                return false;
            maxReach = std::max(maxReach, i + nums.at(i));
        }
        return true;
    }
};
