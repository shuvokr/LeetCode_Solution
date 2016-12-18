//Problem Description: https://leetcode.com/problems/number-of-segments-in-a-string
int countSegments(char* s) 
{
    int ans = 0;
    char* tok = strtok(s, " ");
    while(tok != NULL)
    {
        ans++;
        tok = strtok(NULL, " ");
    }
    return ans;
}
