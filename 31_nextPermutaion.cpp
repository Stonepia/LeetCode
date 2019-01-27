#include <vector>
using namespace std;

class Solution
{
public:
	void nextPermutation(vector<int> &nums)
	{
		if (nums.size() < 2)
			return;
		auto rit = nums.rbegin();
		while ((++rit) != nums.rend()) {
			if (*rit < *(rit - 1))
				break;
		}
		if (rit == nums.rend())
		{
			// All the vector is decendent, just reverse it
			std::reverse(nums.rbegin(), nums.rend());
			return;
		}

		auto upper = nums.rbegin();
		while (*upper <= *rit) {
			upper++;
		}
		
		std::iter_swap(upper, rit);
		std::reverse(nums.rbegin(), rit);
		
	}
};


//Best Solution:
class Solution
{
public:
    void nextPermutation(vector<int>& nums) {
      auto dest = std::is_sorted_until(nums.rbegin(), nums.rend());
      if (dest != nums.rend()) {
        auto target = std::upper_bound(nums.rbegin(), dest, *dest);
        std::iter_swap(dest, target);
      }
      std::reverse(nums.rbegin(), dest);
    }
};