class Solution {
public:
    string reverseWords(string s) {
        string ret = "";
        bool space = false;
        vector<string> v;
        
        char* ch = new char [s.length() + 1];
        strcpy (ch, s.c_str());
        
        char* tok = strtok(ch, " ");
        while(tok != NULL) {
            
            v.push_back(tok);
            tok = strtok(NULL, " ");
        }
        
        for(int i = v.size() - 1; i > -1; i--) {
            if(space) ret = ret + " ";
            else space = true;
            
            ret += v[i];
        }
        
        return ret;
    }
};
