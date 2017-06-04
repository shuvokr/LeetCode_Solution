// https://leetcode.com/problems/frog-jump/#/description
int len, mamo[1111][2111], ind;
unordered_map<int, int> mark;
vector<int> v;
class Solution {
public:
    bool canCross(vector<int>& stones) 
    {
        ind = 1;
        memset(mamo, -1, sizeof mamo);
        mark.clear();
        v = stones;
        len = v.size();
        for(int i = 0; i < len; i++)
            mark[ v[i] ] = i + 1;
        return DP(v[0] + 1, 1);
    }
    int DP(long now, long k)
    {
        if(now == v[len - 1]) return true;
        if(mark.find(now) == mark.end() || now > v[len - 1] || !k) return false;
        
        int x = mark[ now ];
        int &ret = mamo[x][k];
        
        if(ret != -1) return ret;
        ret = DP(now + k - 1, k - 1);
        ret |= DP(now + k, k);
        ret |= DP(now + k + 1, k + 1);
        return ret;
    }
};
