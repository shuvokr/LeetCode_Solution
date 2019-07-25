// Link: https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int time;
    vector<int> pil;
    int minEatingSpeed(vector<int>& piles, int H) {
        pil = piles; time = H;
        int low = 1, high = 1000000001, mid;
        while(high - low > 1) {
            mid = (high + low) >> 1;
            if(isOk(mid)) low = mid;
            else high = mid;
        }
        if(isOk(low)) return high;
        return low;
    }
    bool isOk(int val) {
        int total = 0;
        for(int i = 0; i < pil.size(); i++) {
            total += (pil[i] / val);
            if(pil[i] % val) total++;
        }
        return total > time;
    }
};
