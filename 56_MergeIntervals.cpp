#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * Definition for an interval.
 */
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
  public:
    static bool comp(Interval &lhs, Interval &rhs)
    {
        return lhs.start < rhs.start;
    }
    vector<Interval> merge(vector<Interval> &intervals)
    {
        vector<Interval> res;
        if (intervals.empty())
            return res;
        sort(intervals.begin(), intervals.end(), comp);

        Interval tempInt;
        tempInt.start = intervals.at(0).start;
        tempInt.end = intervals.at(0).end;

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals.at(i).start > tempInt.end)
            {
                res.push_back(tempInt);
                tempInt.start = intervals.at(i).start;
                tempInt.end = intervals.at(i).end;
            }
            else if (intervals.at(i).end > tempInt.end)
            {
                tempInt.end = intervals.at(i).end;
            }
        }
        res.push_back(tempInt);
        return res;
    }
};