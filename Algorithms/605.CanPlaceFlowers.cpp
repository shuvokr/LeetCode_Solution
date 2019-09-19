class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int possible = 0, len = flowerbed.size();
        
        for(int i = 0; i < len; ++i)
            if(flowerbed[i] == 0 && (i + 1 == len || flowerbed[i + 1] == 0)) possible++, i++;
            else if(flowerbed[i] == 1) i++;
        
        return n <= possible;
    }
};
