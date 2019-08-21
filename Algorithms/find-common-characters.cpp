// Link : https://leetcode.com/problems/find-common-characters

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int a[26], b[26];
        memset(a, -1, sizeof a);
        for(int i = 0; i < A.size(); i++) {
            memset(b, 0, sizeof b);
            for(int j = 0; j < A[i].size(); j++) {
                b[ A[i][j] - 'a' ]++;
            }
            for(int j = 0; j < 26; j++) {
                a[j] = a[j] == -1 ? b[j] : b[j] < a[j] ? b[j] : a[j];
            }
        }
        vector<string> ret;
        string str[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
        for(int i = 0; i < 26; i++) {
            if(a[i] == 0) continue;
            for(int j = 0; j < a[i]; j++)
                ret.push_back(str[i]);
        }
        return ret;
    }
};
