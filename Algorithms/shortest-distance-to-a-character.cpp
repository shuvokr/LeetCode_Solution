// Link: https://leetcode.com/problems/shortest-distance-to-a-character/description/

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int len = S.size();
        vector<int> distance;
        for(int i = 0; i < len; i++)
        {
            distance.push_back(10001);
            if(S[i] == C)
            {
                distance[ i ] = 0;
                int j = i - 1;
                while(j > -1 && S[j] != C) distance[ j ] = distance[j + 1] + 1, j--;
            }
        }
        for(int i = len - 1; i > -1; i--)
            if(S[i] == C)
            {
                int j = i + 1;
                while(j < len && S[j] != C) distance[ j ] = distance[j - 1] + 1 > distance[ j ] ? 
                                                            distance[ j ] : distance[j - 1] + 1, j++;
            }
        return distance;
    }
};
