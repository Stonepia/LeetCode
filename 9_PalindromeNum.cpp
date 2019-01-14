#include <string>
using namespace std;
class Solution
{
  public:

    bool isPalindrome(int x)
    {
        string str;
        str = std::to_string(x);
        int len = str.length();
        if(len == 0)
            return false;
        auto beg = str.cbegin();
        auto end = str.crbegin();
        auto mid = beg + (len / 2);
        while (beg != mid)
        {
            if(*beg != *end)
                return false;
            else{
                beg++;
                end++;
            }
        }
        return true;
    }
};