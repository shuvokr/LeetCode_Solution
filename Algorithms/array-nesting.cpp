// Link : https://leetcode.com/problems/array-nesting

class Solution {
public:
    int mamo[ 20001 ];
    bool mark[ 20001 ];
    vector<int> v;
    int arrayNesting(vector<int>& nums) {
        int ret = 1; v = nums;
        memset(mamo, -1, sizeof mamo);
        memset(mark, false, sizeof mark);
        for(int i = 0; i < nums.size(); i++) {
            if(mark[i]) ret = max(ret, mamo[i]);
            else ret = max(ret, DFS(i));
        }
        return ret;
    }
    int DFS(int pos) {
        int &ret = mamo[ pos ];
        if(mark[ pos ]) return ret;
        mark[ pos ] = true; ret = 0;
        return ret = max(ret, 1 + DFS(v[pos]));
    }
};
