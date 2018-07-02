// Link: https://leetcode.com/problems/pascals-triangle-ii/description/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int mamo[35][35];
        vector<int> ret;
        if(!rowIndex)
        {
            ret.push_back(1);
            return ret;
        }
        mamo[0][0] = 1; rowIndex++;
        for(int i = 1; i < rowIndex; i++)
        {
            mamo[i][0] = mamo[i][i] = 1;
            for(int j = 1; j < i; j++) mamo[i][j] = mamo[i - 1][j - 1] + mamo[i - 1][j];
        }
        for(int i = 0; i < rowIndex; i++) ret.push_back(mamo[rowIndex - 1][i]);
        return ret;
    }
};
