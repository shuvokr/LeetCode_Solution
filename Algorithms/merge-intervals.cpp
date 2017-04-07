//Problem Description: https://leetcode.com/problems/merge-intervals
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        //sort(intervals.begin(), intervals.end());
        vector <pair<int, int>> v;
        pair<int, int> pi;
        for(int i = 0; i < intervals.size(); i++)
        {
            pi = make_pair(intervals[i].start, intervals[i].end);
            v.push_back(pi);
        }
        sort(v.begin(), v.end());
        
        vector <Interval> ret;
        Interval tmp;
        for(int i = 0, fst, lst; i < v.size(); i++)
        {
            fst = v[i].first;
            lst = v[i].second;
            while(i + 1 < v.size() && lst >= v[i+1].first) lst = v[i+1].second > lst ? v[i+1].second : lst, i++;
            tmp = Interval(fst, lst);
            ret.push_back(tmp);
        }
        return ret;
    }
};
