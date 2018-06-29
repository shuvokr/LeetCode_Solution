// Link: https://leetcode.com/problems/goat-latin/description/

class Solution {
public:
    string toGoatLatin(string S) {
        string add = "a", ans;
        int len = S.size(), a = 0, b = 0;
        for(int i = 0; i < len; i++)
        {
            if(S[i + 1] == ' ' || i + 1 == len)
            {
                b = ans.size();
                ans += S[i];
                if(isok(ans[a])) ans += "ma";
                else
                {
                    char c = ans[a];
                    for(int j = a; j < b; j++) ans[j] = ans[j+1]; ans[b] = c;
                    ans += "ma";
                }
                ans += add;
                a = b + 4 + add.size();
                add += "a";
            }
            else ans += S[i];
        }
        return ans;
    }
    bool isok(char c)
    {
        return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
    }
};
