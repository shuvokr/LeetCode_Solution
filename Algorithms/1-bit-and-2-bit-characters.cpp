https://leetcode.com/problems/1-bit-and-2-bit-characters/description/

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int  len = bits.size();
        bool ret = len == 1 || !bits[len - 2];
        if(ret) return true;
        for(int i = 0; i < len; i++) i += bits[i], ret = ret || (i == len - 2);
        return ret;
    }
};
