//Link: https://leetcode.com/problems/score-after-flipping-matrix/description/

class Solution {
public:
    int matrixScore(vector<vector<int>>& a) {
        int row = a.size(), col = a[0].size(), mamo[20], p = row > col ? row : col;
        mamo[0] = 1;
        for(int i = 1; i < p; i++) mamo[i] = mamo[i - 1] << 1; 
        int answer = 0, ans;
        
        for(int k = 0;; k++)
        {
            bool ck = true;
            for(int j = 0, one = 0; j < col; j++, one = 0)
            {
                for(int i = 0; i < row; i++) one += a[i][j];
                ck = row - one > one ? false : ck;
                if(row - one > one)
                    for(int i = 0; i < row; i++) a[i][j] = !a[i][j];
            }
            if(ck) break;
            else
            for(int i = 0; i < row; i++)
            {
                if(!a[i][0])
                    for(int j = 0; j < col; j++) a[i][j] = !a[i][j];
            }
        }
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++) answer += a[i][j] ? mamo[col - j - 1] : 0;
        ans = answer; answer = 0;
        
        for(int k = 0;; k++)
        {
            bool ck = true;
            for(int i = 0; i < row; i++)
            {
                ck = !a[i][0] ? false : ck;
                if(!a[i][0])
                    for(int j = 0; j < col; j++) a[i][j] = !a[i][j];
            }
            
            if(ck) break;
            else
            for(int j = 0, one = 0; j < col; j++, one = 0)
            {
                for(int i = 0; i < row; i++) one += a[i][j];
                if(row - one > one)
                    for(int i = 0; i < row; i++) a[i][j] = !a[i][j];
            }
        }
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++) answer += a[i][j] ? mamo[col - j - 1] : 0;
        return answer > ans ? answer : ans;
    }
};
