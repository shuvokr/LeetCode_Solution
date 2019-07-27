// Link : https://leetcode.com/problems/occurrences-after-bigram/
// Tag : Greedy

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ret;
        int len = text.size(), count = 1;
        char charArray[len + 1];
        strcpy(charArray, text.c_str());
        char * tok;
        tok = strtok(charArray, " ");
        while(tok != NULL) {
            if(count == 1) {
                if(first == tok) count++;
                tok = strtok(NULL, " ");
                continue;
            }
            if(count == 2) {
                if(second == tok) {
                    count++;
                    tok = strtok(NULL, " ");
                    continue;
                }
                count = 1;
                if(tok == first) count++;
                if(first == second) count++;
                tok = strtok(NULL, " ");
                continue;
            }
            
            count = 1;
            ret.push_back(tok);
            if(tok == first) count++;
            if(first == second) count++;
            tok = strtok(NULL, " ");
        }
        return ret;
    }
};
