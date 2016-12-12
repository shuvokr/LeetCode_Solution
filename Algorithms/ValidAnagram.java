//Problem Description: https://leetcode.com/problems/valid-anagram
public class Solution 
{
    public boolean isAnagram(String s, String t) 
    {
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        String sorted = new String(chars);
        
        char[] charr = t.toCharArray();
        Arrays.sort(charr);
        String sorteed = new String(charr);
        
        System.out.println(sorted + " " + sorteed);
        
        return sorted.equals(sorteed);
    }
}
