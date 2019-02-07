#include <string>
using namespace std;

class Solution
{
  public:
    string multiply(string num1, string num2)
    {
        if (num1.empty() || num2.empty() || num1 == "0" || num2 == "0")
            return "0";
        int len1 = num1.size(), len2 = num2.size();
        string res(len1 + len2, '0');

        for (int i = len1 - 1; i >= 0; i--)
        {
            for (int j = len2 - 1; j >= 0; j--)
            {
                int val = (num1.at(i) - '0') * (num2.at(j) - '0') + (res.at(i + j + 1) - '0');
                res.at(i + j + 1) = val % 10 + '0';
                res.at(i + j) = val / 10 + '0' + res.at(i + j) - '0';
            }
        }
        return (res.at(0) == '0') ? res.substr(1) : res;
    }
};