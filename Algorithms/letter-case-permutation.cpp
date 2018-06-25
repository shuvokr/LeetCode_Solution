// Link: https://leetcode.com/problems/letter-case-permutation/description/

class Solution {
public:
    char input[ 13 ];
    int len;
    vector<string> ret;
    vector<string> letterCasePermutation(string S) {
        len = S.size();
        for(int i = 0; i < len; i++)
            input[ i ] = isdigit(S[ i ]) ? S[ i ] : tolower( S[ i ] );
        backtrack(0);
        return ret;
    }
    void backtrack(int pos)
    {
        if(pos == len)
        {
            ret.push_back( input );
            return;
        }
        if(isdigit(input[ pos ]) || islower(input[ pos ])) backtrack( pos + 1 );
        if(!isdigit(input[ pos ]))
        {
            input[ pos ] -= 32;
            backtrack(pos + 1);
            input[ pos ] += 32;
        }
    }
};
