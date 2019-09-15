class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // balloon
        int mamo[123];
        memset(mamo, 0, sizeof mamo);
        for(int i = 0; i < text.size(); i++)
            mamo[ text[i] ]++;
        int ret;
        ret = min(mamo['b'], min(mamo['a'], min(mamo['l'] / 2, min(mamo['o'] / 2, mamo['n']))));
        return ret;
    }
};
