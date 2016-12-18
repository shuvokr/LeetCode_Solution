//Problem Description: https://leetcode.com/problems/longest-substring-without-repeating-characters
class Solution 
{
public: 
    int lengthOfLongestSubstring(string inputStr) 
    {
        
	#define CLER(name, val) memset(name, val, sizeof name)
        bool markRep[129];
        
        //Solution Process
        int ret = 0, subStrLen = 0;
        CLER(markRep, true);
        for(int i = 0; i < inputStr.size(); i++)
        {
        	if(markRep[ inputStr[ i ] ])
        	{
        		markRep[ inputStr[ i ] ] = false;
        		subStrLen++;
			}
			else
			{
				CLER(markRep, true);
				markRep[ inputStr[ i ] ] = false;
				ret = subStrLen > ret ? subStrLen : ret;
				int j = i - 1; subStrLen = 1;
				while(inputStr[ j ] != inputStr[ i ])
				{
					markRep[ inputStr[ j ] ] = false;
					subStrLen++;
					j--;
				}	
			}
			ret = subStrLen > ret ? subStrLen : ret;
		}
    	return ret;
	}
};
