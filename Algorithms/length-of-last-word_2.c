// https://leetcode.com/problems/length-of-last-word/#/description
int lengthOfLastWord(char* s) 
{
    int ret = 0, len = strlen(s) - 1;
    while(len > -1 && s[len] == ' ') len--;
    while(len > -1 && s[len] != ' ') ret++, len--;
    return ret;
}
