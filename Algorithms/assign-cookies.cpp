// Link: https://leetcode.com/problems/assign-cookies/description/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int leng = g.size(), lens = s.size(), a = 0, b = 0, answer = 0;
        for(;a < leng && b < lens;)
        {
            if(s[b] >= g[a]) answer++, a++, b++;
            else b++;
        }
        return answer;
    }
};
