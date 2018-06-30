// Link: https://leetcode.com/problems/rotate-string/description/

class Solution {
public:
    bool rotateString(string A, string B) {
        int lena = A.size(), lenb = B.size();
        if(lena != lenb) return false;
        if(!lena && !lenb) return true;
        for(int i = 0; i < lena; i++)
        {
            if(A[ i ] == B[ 0 ])
            {
                int k = i + 1 == lena ? 0 : i + 1;
                for(int x = 1; x < lenb; x++)
                {
                    if(A[k] == B[x])
                    {
                        k++; k = k == lena ? 0 : k;
                        continue;
                    }
                    k = lena; x = lenb;
                }
                if(k != lena) return true;
            }
        }
        return false;
    }
};
