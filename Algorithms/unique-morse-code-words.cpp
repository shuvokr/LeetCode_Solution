// Link: https://leetcode.com/problems/unique-morse-code-words/description/
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        map<char, string> mp;
        map<string, int> result;
        string temp;
        mp['a'] = ".-";
        mp['b'] = "-...";
        mp['c'] = "-.-.";
        mp['d'] = "-..";
        mp['e'] = ".";
        mp['f'] = "..-.";
        mp['g'] = "--.";
        mp['h'] = "....";
        mp['i'] = "..";
        mp['j'] = ".---";
        mp['k'] = "-.-";
        mp['l'] = ".-..";
        mp['m'] = "--";
        mp['n'] = "-.";
        mp['o'] = "---";
        mp['p'] = ".--.";
        mp['q'] = "--.-";
        mp['r'] = ".-.";
        mp['s'] = "...";
        mp['t'] = "-";
        mp['u'] = "..-";
        mp['v'] = "...-";
        mp['w'] = ".--";
        mp['x'] = "-..-";
        mp['y'] = "-.--";
        mp['z'] = "--..";
        int len = words.size();
        for(int i = 0; i < len; i++)
        {
            int ln = words[i].size();
            temp = "";
            for(int j = 0; j < ln; j++) temp += mp[ words[i][j] ];
            result[ temp ]++;
        }
        return result.size();
    }
};
