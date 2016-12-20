//Problem Description: https://leetcode.com/problems/contains-duplicate-ii
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        if(!k || nums.empty()) return false;
        int len = nums.size(), mn = 1000000000, mx = -1000000000;
        for(int i = 0; i < len; i++) 
        {
            mx = mx < nums[ i ] ? nums[ i ] : mx;
            mn = mn > nums[ i ] ? nums[ i ] : mn;
        }
        mx = mx < 0 ? -mx : mx;
        mn = mn < 0 ? -mn : mn;
        mx += mn + 2;
        for(int i = 0; i < len; i++) nums[ i ] += mn;
        vector<vector<int>> vNums;
        set<int> st;
        set<int>::iterator it;
        vNums.assign(mx + mx, vector<int>());
        for(int i = 0; i < len; i++)
        {
            vNums[ nums[i] ].push_back( i );
            st.insert(nums[ i ]);
        }
        len = st.size();
        for(it = st.begin(); it != st.end(); it++)
        {
            int x = *it, tLen = vNums[x].size();
            for(int i = 1; i < tLen; i++)
                if(vNums[x][ i ] - vNums[x][i - 1] <= k) return true;
        }
        return false;
    }
};
