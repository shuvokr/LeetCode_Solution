// Link: https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> mp, sum;
        int len1 = list1.size(), len2 = list2.size(), mx = -1, smx = 100000;
        for(int i = 0; i < len1; i++) mp[ list1[i] ]++, mx = mp[ list1[i] ] < mx ? mx : mp[ list1[i] ], sum[list1[i]] = i;
        for(int i = 0; i < len2; i++) 
        {
            mp[ list2[i] ]++, mx = mp[ list2[i] ] < mx ? mx : mp[ list2[i] ];
            sum[list2[i]] += i;
        }
        for(int i = 0; i < len2; i++) 
        {
            if(mp[list2[i]] == mx) smx = smx > sum[list2[i]] ? sum[list2[i]] : smx;
        }
        list1.clear();
        for(map<string, int>:: iterator it = mp.begin(); it != mp.end(); it++)
            if(it->second == mx && sum[it->first] == smx) list1.push_back(it->first);
        return list1;
    }
};
