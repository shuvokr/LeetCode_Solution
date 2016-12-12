import java.util.*;
class Solution 
{
	public String convert(String s, int numRows) 
	{
	    if(numRows == 1) return s;
	    
		String ret = new String();
		int len = s.length(), point = ((numRows - 1) << 1), a = point, b = 0;
		
		for(int i = 0; i < numRows; i++)
		{
			if(i == 0 || i + 1 == numRows)
				for(int j = i; j < len; j += point) ret += s.charAt( j );
			else
			{
				boolean flag = true;
				int jump = a;
				for(int j = i; j < len; j += jump)
				{
					ret += s.charAt( j );
					if(flag)
					{
						flag = false;
						jump = a;
					}
					else
					{
						flag = true;
						jump = b;
					}
				}
			}
			a -= 2;
			b += 2;
		}
		
		return ret;
    }
}
class ZigZag
{
	public static void main(String args[])
	{
		Scanner sf = new Scanner(System.in);
		String str = sf.nextLine();
		int nRow = sf.nextInt();
		
		Solution ck = new Solution();
		String res = ck.convert(str, nRow);
		System.out.println( res );
	}
}
