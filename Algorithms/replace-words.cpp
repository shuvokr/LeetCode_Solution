// https://leetcode.com/problems/replace-words
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) 
    {
        unordered_map<string, bool> mp;
        string tmp, ret;
        int i = 0, len = sentence.size(), ln = dict.size();
        for(int j = 0; j < ln; j++) mp[ dict[j] ] = true;
        while(i < len)
        {
            tmp = "";
            while(i < len && sentence[i] != ' ')
            {
                tmp += sentence[i];
                if(mp.find(tmp) != mp.end()) break;
                i++;
            }
            while(i < len && sentence[i] != ' ') i++;
            ret += tmp;
            if(sentence[i] == ' ') ret += sentence[i++];
        }
        return ret;
    }
};
