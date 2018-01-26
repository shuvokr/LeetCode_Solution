// https://leetcode.com/problems/baseball-game/description/

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int dataArray[1005], ind = 0, res = 0, len = ops.size(), val, total;
        for(int i = 0; i < len; i++)
            if(ops[i][0] == '+') res += ind < 1 ? 0 : ind < 2 ? dataArray[ind - 1] : dataArray[ind - 1] + dataArray[ind - 2],
                                 dataArray[ind] = ind < 1 ? 0 : ind < 2 ? dataArray[ind - 1] : dataArray[ind - 1] + dataArray[ind - 2], 
                                 ind += ind > 0 ? 1 : 0;
            else if(ops[i][0] == 'D') res += ind < 1 ? 0 : (dataArray[ind - 1] << 1), dataArray[ind] = ind < 1 ? 0 : 
                                 (dataArray[ind - 1] << 1), ind += ind ? 1 : 0;
            else if(ops[i][0] == 'C') res -= ind < 1 ? 0 : dataArray[ind - 1], ind -= ind < 1 ? 0 : 1;
            else
            {
                total = 0;
               for(int j = ops[i].size() - 1, s = 1; j > -1; j--, s *= 10)
                   if(ops[i][j] == '-') total *= -1;
                   else total += (ops[i][j] - 48) * s;
                res += total; dataArray[ind++] = total;
            }
        return res;
    }
};
