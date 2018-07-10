//Link: https://leetcode.com/problems/partition-labels/description/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ret;
        int len = S.size(), lastPosition[ 26 ], neg = 'a', lp = 0;
        memset(lastPosition, -1, sizeof lastPosition);
        for(int i = len - 1; i > -1; i--) lastPosition[ S[i]-neg ] = lastPosition[ S[i]-neg ] == -1 ? i : lastPosition[ S[i]-neg ];
        for(int i = 0; i < len;)
        {
            lp = lastPosition[ S[i]-neg ];
            for(int j = i; j < lp; j++)
                lp = lastPosition[ S[j]-neg ] > lp ? lastPosition[ S[j]-neg ] : lp;
            ret.push_back(lp - i + 1);
            i = lp + 1;
        }
        return ret;
    }
};
