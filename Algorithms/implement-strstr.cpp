// https://leetcode.com/problems/implement-strstr/#/description
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int len2 = haystack.size(), len1 = needle.size();
        long long hashValue = 0, hashValue2 = 0;
        
        if(len2 < len1) return -1;
        if(!len1 && !len2) return 0;
        const long long p = 999983, mod = 1000000007;
        
        for(int i = 0; i < len1; i++)
            hashValue = (hashValue + ((needle[i] % mod) * (bigMod(p, len1 - i - 1, mod) %mod )) % mod) % mod;
        
        for(int i = 0; i < len1; i++)
            hashValue2 = (hashValue2 + ((haystack[i] % mod) * (bigMod(p, len1 - i - 1, mod) %mod )) % mod) % mod;        
        int ret = 0;
        if(hashValue == hashValue2) return ret;
        //cout << hashValue << " " << hashValue2 << endl;
        
        for(int i = len1; i < len2; i++)
        {
            hashValue2 = hashValue2 - ((haystack[i - len1] * bigMod(p, len1 - 1, mod)) % mod);
            hashValue2 += (mod << 1ll);
            hashValue2 %= mod;
            hashValue2 *= p;
            hashValue2 %= mod;
            hashValue2 += haystack[i];
            hashValue2 %= mod;
            ret++;
            if(hashValue2 == hashValue) return ret;
        }
        return -1;
    }
    long long bigMod(long long num, long long p, long long mod)
    {
        if(p == 0) return 1ll;
        if(p == 1) return num;
        if(p % 2ll == 1) return (num * (bigMod(num, p - 1ll, mod) % mod)) % mod;
        else
        {
            long long tmp = bigMod(num, p >> 1ll, mod) % mod;
            tmp *= tmp; tmp %= mod;
            return tmp;
        }
    }
};
