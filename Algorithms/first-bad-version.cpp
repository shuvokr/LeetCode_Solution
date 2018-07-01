// Link: https://leetcode.com/problems/first-bad-version/description/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long mid, left = 1, right = n;
        for(;right - left > 1;)
        {
            mid = (left + right) >> 1;
            if(isBadVersion(mid)) right = mid;
            else left = mid;
        }
        return isBadVersion(left) ? left : right;
    }
};
