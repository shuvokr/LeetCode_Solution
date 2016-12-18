//Problem Description: https://leetcode.com/problems/reverse-string
public class Solution 
{
    public String reverseString(String s) 
    {
        return new StringBuilder(s).reverse().toString();   
    }
}
