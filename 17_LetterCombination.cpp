#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
  public:
    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> result;
        if (digits.empty())
            return result;
        result.push_back("");

        for (int k = 0; k < digits.size(); ++k)
        {
            vector<string> temp;
            for (int i = 0; i < result.size(); ++i)
            {
                for (int j = 0; j < mp[digits[k]].size(); ++j)
                    temp.push_back(result[i] + mp[digits[k]][j]);
            }
            result = temp;
        }
        return result;
    }
};