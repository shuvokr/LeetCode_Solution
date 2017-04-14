//Problem Description: https://leetcode.com/problems/encode-and-decode-tinyurl
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int cou = 1;
class Solution {
public:
    unordered_map<string, string> mp;
    unordered_map<string, string> pm;
    string str = "http://tinyurl.com/";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string s;
        if(mp.find(longUrl) == mp.end())
        {
            s = str + toString( cou );
            mp[ longUrl ] = s;
            pm[ s ] = longUrl;
        }
        else s = mp[ longUrl ];
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return pm[ shortUrl ];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
