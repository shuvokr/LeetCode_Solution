// Link: https://leetcode.com/problems/number-of-boomerangs/description/

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) 
    {
        int len = points.size(), answer = 0, mamo[501];
        mamo[1] = mamo[0] = 0; mamo[2] = 2;
        for(int i = 3; i < len; i++) mamo[i] = mamo[i-1] + 2;  
        map<int, int> mp;
        for(int i = 0; i < len; i++)
        {
            for(int j = 0, dis; j < len; j++)
                if(i != j)
                { 
                    dis = distance(points[i].first - points[j].first, points[i].second - points[j].second);
                    answer +=  mamo[ ++mp[dis] ];
                }
            mp.clear();
        }
        return answer;
    }
    int distance(int x, int y)
    {
        return x * x + y * y;
    }
};
