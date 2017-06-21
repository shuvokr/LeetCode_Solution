// https://leetcode.com/problems/power-of-four/#/description
bool isPowerOfFour(int num) 
{
    if(num == 1) return true;
    if(num&1 || !num) return false;
    int x = sqrt(num);
    if(x&1 || x*x != num) return false;
    int p = log10(x)/log10(2);
    return (x == 1 << p);
}
