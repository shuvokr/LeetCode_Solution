//Problem Description: https://leetcode.com/problems/keyboard-row
class Solution {
public:
    unordered_map<char, int> mp;
    vector<string> findWords(vector<string>& words) 
    {
        vector<string> ret;
        precalculate();
        int len = words.size();
        for(int i = 0; i < len; i++)
            if(ck(words[i])) ret.push_back(words[ i ]);
        return ret;
    }
    bool ck(string str)
    {
        int len = str.size(), tmp = mp[ str[0] ];
        for(int i = 0; i < len; i++)
            if(tmp != mp[str[i]]) return false;
        return true;
    }
    void precalculate()
    {
        mp['a'] = mp['A'] = 1;
        mp['s'] = mp['S'] = 1;
        mp['d'] = mp['D'] = 1;
        mp['f'] = mp['F'] = 1;
        mp['g'] = mp['G'] = 1;
        mp['h'] = mp['H'] = 1;
        mp['j'] = mp['J'] = 1;
        mp['k'] = mp['K'] = 1;
        mp['l'] = mp['L'] = 1;
        
        mp['q'] = mp['Q'] = 2;
        mp['w'] = mp['W'] = 2;
        mp['e'] = mp['E'] = 2;
        mp['r'] = mp['R'] = 2;
        mp['t'] = mp['T'] = 2;
        mp['y'] = mp['Y'] = 2;
        mp['u'] = mp['U'] = 2;
        mp['i'] = mp['I'] = 2;
        mp['o'] = mp['O'] = 2;
        mp['p'] = mp['P'] = 2;
        
        mp['z'] = mp['Z'] = 3;
        mp['x'] = mp['X'] = 3;
        mp['c'] = mp['C'] = 3;
        mp['v'] = mp['V'] = 3;
        mp['b'] = mp['B'] = 3;
        mp['n'] = mp['N'] = 3;
        mp['m'] = mp['M'] = 3;
    }
};
