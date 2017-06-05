// https://leetcode.com/problems/roman-to-integer/#/description
int romanToInt(char* s) 
{
    int i, len = strlen(s), val[ 'Y' ], ret = 0;
    val['I'] = 1; val['V'] = 5; val['X'] = 10; val['L'] = 50; val['C'] = 100; val['D'] = 500; val['M'] = 1000;
    
    ret = val[ s[len - 1] ];
    for(i = len - 2; i > -1; i--)
        ret += val[ s[i] ] < val[ s[i+1] ] ? -val[ s[i] ] : val[ s[i] ];
    return ret;
}
