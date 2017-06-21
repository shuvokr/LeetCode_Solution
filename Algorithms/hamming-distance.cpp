// https://leetcode.com/problems/hamming-distance/#/description
class Solution {
public:
    int hammingDistance(int x, int y) 
    {
        bool xx[33], yy[33];
        for(int i = 0; i < 33; i++) xx[i] = yy[i] = false;
        int indx = 0, ret = 0;
        while( x )
        {
            xx[ indx++ ] = (x&1);
            x >>= 1;
        }
        
        int indy = 0;
        while( y )
        {
            yy[ indy ] = (y&1);
            y >>= 1;
            ret += !(xx[indy] == yy[indy]);
            indy++;
        }
        if(indy < indx)
            for(int i = indy; i < indx; i++)
                ret += !(xx[i] == yy[i]);
        return ret;
    }
};
