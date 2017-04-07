//Problem Description: https://leetcode.com/problems/top-k-frequent-elements
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map <int, int> mp;
        vector <int> ret;
        vector < pair<int, int> > v;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]]++;
        for(map<int, int>:: iterator it = mp.begin(); it!=mp.end() ; it++)
        {
            pair<int, int> pi = make_pair(it->second, it->first);
            v.push_back(pi);
        }
        sort(v.begin(), v.end());
        int x = v.size() - 1;
        while(k--) ret.push_back(v[x--].second);
        sort(ret.begin(), ret.end());
        return ret;
    }
};
