// Link: https://leetcode.com/problems/daily-temperatures/description/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        map<int, int> mp;
        vector<int> answer;
        for(int i = temperatures.size() - 1, point = 30003; i > -1; i--, point = 30003)
        {
            for(map<int, int> :: iterator it = mp.begin(); it != mp.end(); it++) 
                if(it->first > temperatures[i])
                    point = it->second < point ? it->second : point;
            mp[temperatures[i]] = i;
            point = point == 30003 ? i : point; 
            answer.push_back(point - i);
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
