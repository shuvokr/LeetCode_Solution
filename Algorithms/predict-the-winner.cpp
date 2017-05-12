//Problem Description: https://leetcode.com/problems/predict-the-winner/#/description
class Solution {
    vector<int> scores;
    const int inf = -900000000;
public:
    int mamo[ 20 ][ 20 ][ 2 ];
    bool PredictTheWinner(vector<int>& nums) {
        scores = nums;
        int len = nums.size();
        for(int i = 0; i < len; i++)
            for(int j = 0; j < len; j++)
                for(int k = 0; k < 2; k++) mamo[i][j][k] = inf;
        int maxScoreFor1stPlayer = DP(0, len - 1, true);
        //cout << maxScoreFor1stPlayer << endl;
        return (maxScoreFor1stPlayer > -1);
    }
    int DP(int leftPoint, int rightPoint, int flag)
    {
        if(leftPoint == rightPoint) return scores[ leftPoint ];
        if(leftPoint > rightPoint) return 0;
        int &ret = mamo[ leftPoint ][ rightPoint ][ flag ];
        if(ret != inf) return ret;
        if(flag)
            ret = max(DP(leftPoint + 1, rightPoint, false) + scores[ leftPoint ], DP(leftPoint, rightPoint - 1, false) + scores[ rightPoint ]);
        else
            ret = min(DP(leftPoint + 1, rightPoint, true) - scores[ leftPoint ], DP(leftPoint, rightPoint - 1, true) - scores[ rightPoint ]);
        return ret;
    }
};
