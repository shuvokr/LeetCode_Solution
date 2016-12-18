//Problem Description: https://leetcode.com/problems/reverse-vowels-of-a-string
class Solution 
{
public:
    string reverseVowels(string s) 
    {
        int low = 0, high = s.size() - 1;
        while(low < high)
        {
            while(low < high && !isok(s[ low ])) low++;
            while(high > low && !isok(s[ high ])) high--;
            if(low < high)
            {
                char a = s[ low ];
                s[ low ] = s[ high ];
                s[ high ] = a;
                low++; high--;
            }
        }
        return s;
    }
    bool isok(char ch)
    {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ||
                (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
};
