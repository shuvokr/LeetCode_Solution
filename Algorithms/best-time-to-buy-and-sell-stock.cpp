//Problem Description: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/#/description
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int len = prices.size(), mx[ len ], mn[ len ];
        mn[0] = prices[0];
        mx[len - 1] = prices[len - 1];
        for(int i = 1; i < len; i++) mn[i] = prices[i] > mn[i - 1] ? mn[i - 1] : prices[i];
        for(int i = len - 2; i > -1; i--) mx[i] = prices[i] < mx[i + 1] ? mx[i + 1] : prices[i];
        int ret = 0;
        for(int i = 0; i < len; i++) ret = max(ret, mx[i] - mn[ i ]);
        return ret;
    }
};
