https://leetcode.com/problems/subdomain-visit-count/description/

class Solution {
public:
    template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
    unordered_map<string, int> mp;
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        int val = 0, len = cpdomains.size();
        string str = "", tmp;
        
        for(int i = 0, k = 0; i < len; i++)
        {
            k = val = 0;
            for(;; k++)
            {
                if(cpdomains[i][k] == 32) break;
                val = val * 10 + cpdomains[i][k] - 48;
            }
            str = "";
            for(int j = cpdomains[i].size()-1; j > k; j--)
                if(cpdomains[i][j] == '.')
                {
                    tmp = str;
                    reverse(tmp.begin(), tmp.end());
                    mp[tmp] += val;
                    str = str + '.';
                }
                else str = str + cpdomains[i][j];
            
            tmp = str;
            reverse(tmp.begin(), tmp.end());
            mp[tmp] += val;
        }
        vector<string> ret;
        for(unordered_map<string, int> :: iterator it = mp.begin(); it != mp.end(); it++)
        {
            str = it->first;
            tmp = toString(it->second);
            tmp = tmp + " " + str;
            ret.push_back(tmp);
        }
        return ret;
    }
};
