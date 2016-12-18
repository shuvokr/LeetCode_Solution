//Problem Description: https://leetcode.com/problems/reverse-integer
class Solution 
{
    public int reverse(int x) 
    {
        String str = Integer.toString( x );
        String s = new String();
		int last = -1;
		if(str.charAt(0) == '-')
		{
		    last++;
		    s += '-';
		}
		for(int i = str.length() - 1; i > last; i--) s += str.charAt(i);
		
		return myAtoi(s);
    }
	
	public int myAtoi(String str) 
	{
	    if(str.length() == 0) return 0;
	    
		String tmp = new String();
		int len = str.length(), ii = 0;
		while(ii < str.length() && str.charAt(ii) == 32) ii++;
		for(; ii < len; ii++)
		{
		    if(str.charAt(ii) == '+' || str.charAt(ii) == '-' ||(str.charAt(ii) > 47 && str.charAt(ii) < 58)) tmp += str.charAt(ii);
		    else len = ii;
		}
		
		str = new String();
		str += tmp;
		//System.out.println(str + " " + tmp);
		if(str.length() == 0) return 0;
		
		if(str.charAt(0) == '+' || str.charAt(0) == '-' || (str.charAt(0) > 47 && str.charAt(0) < 58))
		{
			if((str.charAt(0) > 47 && str.charAt(0) < 58))
			{
				int i = 0;
				while(i < str.length() && str.charAt( i ) == '0') i++;
				for(; i < str.length(); i++)
					if(str.charAt(i) < 48 || str.charAt(i) > 57) return 0;
			}
			else
			{
				if(str.length() == 1) return 0;
				int i = 1;
				while(i < str.length() && str.charAt( i ) == '0') i++;
				for(; i < str.length(); i++)
					if(str.charAt(i) < 48 || str.charAt(i) > 57) return 0;
			}
		}
		//System.out.println(str + " " + tmp);
		
		int i = 0;
		long num = 0;
		boolean isNeg = false;

		if (str.charAt(0) == '-') 
		{
			isNeg = true;
			i = 1;
		}
		
		while(i < str.length() && str.charAt(i) == '0') i++;

		while( i < str.length()) 
		{
		    if(num > 2147483647) num = 2147483647;
		    if(num < -2147483648) num = -2147483648;
		    int val = str.charAt(i);
		    if(val > 47 && val < 58)
		    {
			    num *= 10;
			    num += str.charAt(i++) - '0';
		    }
		    else i++;
		}
        
		if (isNeg)
			num = -num;
		//System.out.println(num);
		
		if(num > 2147483647) num = 0;
		if(num < -2147483648) num = 0;
		
		return (int)num;
    }
}
