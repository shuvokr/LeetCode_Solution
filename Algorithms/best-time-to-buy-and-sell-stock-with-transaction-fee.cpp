// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    int mamo[50001][2], transactionFee;
    vector<int> todaysPriceList;
    int maxProfit(vector<int>& prices, int fee) {
        todaysPriceList = prices;
        transactionFee = fee;
        memset(mamo, -1, sizeof mamo);
        return DP(0, 0);
    }
    int DP(int position, int state) {
        if(position == todaysPriceList.size()) return 0;
        
        int &ret = mamo[position][state];
        if(ret != -1) return ret;
        
        if( !state ) {
            
            int a = (-1) * todaysPriceList[position] + DP(position + 1, 1);
            int b = DP(position + 1, 0);
            return ret = max(a, b);
        }
        else {
            
            int a = todaysPriceList[position] - transactionFee + DP(position + 1, 0);
            int b = DP(position + 1, 1);
            return ret = max(a, b);
        }
    }
};
