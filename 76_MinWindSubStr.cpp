#include "CommonHeader.h"

// Using a SLiding Window method
class Solution
{
  public:
    string minWindow(string s, string t)
    {
        string res = "";
        if (s.size() < t.size() || (s.empty() && !t.empty()) || (!s.empty() && t.empty()))
            return res;
        vector<int> mp(128, 0);
        for (auto i : t)
            mp.at(i)++;

        int windBeg = 0, windEnd = 0;
        int counter = t.size();
        int minSize = INT_MAX, minStart = 0;

        while (windEnd < s.size())
        {
            if (mp.at(s.at(windEnd++))-- > 0)
            {
                counter--;
            }
            while (counter == 0)
            {
                if (windEnd - windBeg < minSize)
                {
                    minStart = windBeg;
                    minSize = windEnd - windBeg;
                }
                if (mp.at(s.at(windBeg++))++ == 0)
                {
                    counter++;
                }
            }
        }

        return minSize == INT_MAX ? "" : s.substr(minStart, minSize);
    }
};