// Link : https://leetcode.com/problems/rectangle-overlap

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int maxX , minX, maxY, minY;
        
        maxX = rec2[0] < rec2[2] ? rec2[2] : rec2[0];
        minX = rec2[0] < rec2[2] ? rec2[0] : rec2[2];
        
        maxY = rec2[1] < rec2[3] ? rec2[3] : rec2[1];
        minY = rec2[1] < rec2[3] ? rec2[1] : rec2[3];
        
        return max(rec1[0], rec1[2]) <= minX ? false : maxX <= min(rec1[0], rec1[2]) ?
            false : max(rec1[1], rec1[3]) <= minY ? false : maxY <= min(rec1[1], rec1[3]) ?
                false : true;
    }
};
