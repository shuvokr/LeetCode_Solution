// Link : https://leetcode.com/problems/h-index

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int ret = 0;
        for(int i = citations.size() - 1, val; i > -1; i--) {
            val = citations.size() - i;
            if(i - 1 == -1) {
                ret = citations[i] >= val ? val : ret;
            }
            else {
                ret = citations[i - 1] <= val && citations[i] >= val ? val : ret;
            }
        }
        return ret;
    }
};
