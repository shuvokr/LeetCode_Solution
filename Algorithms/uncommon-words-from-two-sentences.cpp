// Link : https://leetcode.com/problems/uncommon-words-from-two-sentences

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> ret;
        unordered_map<string, int> mark;
        mark.clear();
        
        char ch[A.size() + 2];
        strcpy(ch, A.c_str());
        char * tok;
        tok = strtok(ch, " ");
        while(tok != NULL) {
            mark[ tok ]++;
            tok = strtok(NULL, " ");
        }
        
        char chh[B.size() + 2];
        strcpy(chh, B.c_str());
        char * tokk;
        tokk = strtok(chh, " ");
        while(tokk != NULL) {
            mark[ tokk ]++;
            tokk = strtok(NULL, " ");
        }
        
        for(auto& it: mark) 
            if(mark[it.first] == 1)
                ret.push_back(it.first);
        return ret;
    }
};
