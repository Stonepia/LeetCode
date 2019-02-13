#include <vector>
#include <algorithm>
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

// Naive Solution
class Solution
{
  public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
    {
        vector<Interval> res;
        if (intervals.empty())
        {
            res.push_back(newInterval);
            return res;
        }
        Interval temp;
        temp.start = newInterval.start;
        temp.end = newInterval.end;

        for (int i = 0; i < intervals.size(); ++i)
        {
            if (intervals.at(i).end < temp.start)
                res.push_back(intervals.at(i));
            else if (intervals.at(i).start > temp.end)
            {
                res.push_back(temp);
                res.insert(res.end(), intervals.begin() + i, intervals.end());
                return res;
            }
            else if (intervals.at(i).end >= temp.start || intervals.at(i).start <= temp.end)
            {
                temp.start = min(intervals.at(i).start, temp.start);
                temp.end = max(intervals.at(i).end, temp.end);
            }
        }

        if (res.empty() || res.back().end < temp.start)
            res.push_back(temp);

        return res;
    }
};

// Using STL Equal Range

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        auto compare = [](const Interval &lhs, const Interval &rhs) {
            return lhs.end < rhs.start;
        };
        auto range = equal_range(intervals.begin(), intervals.end(), newInterval, compare);
        auto it1 = range.first;
        auto it2 = range.second;
        if(it1 == it2)
            intervals.insert(it1, newInterval);
        else{
            it2--;
            it2->start = min(newInterval.start, it1->start);
            it2->end = max(newInterval.end, it2->end);
            intervals.erase(it1, it2);
        }
        return intervals;
    }
};