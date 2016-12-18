//Problem Description: https://leetcode.com/problems/circular-array-loop
class Solution 
{
public:
    int len;
	bool circularArrayLoop(vector<int>& nums) 
	{
	    len = nums.size();
		return solve( nums.size(), nums );
    }
	bool solve(int n, vector<int> v)
	{
		int mark[ n + 5 ], ck = 1, last;
		memset(mark, 0, sizeof mark);
		for(int ii = 0; ii < n; ii++)
		{
			int p = ii;
			int i = ii;
			int a = 0, b = 0;
			//printf("%d ", p);
			while( mark[ p ] != ck )
			{
				last = p;
				mark[ p ] = ck;
				int x = v[ i ];
				if(x < 0) a = 1;
				else b = 1;
				if(a && b) break;
	    		if(x < 0)
	    		{
	    			x *= (-1);
	    			if(x > i + 1)
	    			{
	    				x -= i;
	    				int mod = x % len;
	    				p = len - mod;
					}
					else p = i - x;
				}
				else
				{
	    			if(x + i >= len)
	    			{
	    				x -= (len - i - 1);
	    				p = x - 1;
	    				p %= len;
					}
					else p = i + x;
				}
				if(last == p)
				{
					mark[ p ] = 0;
					break;
				}
				i = p;
				//printf("%d ", p);
			}
			if(!a || !b)
			if(v[last] * (-1) != v[ p ])
			    if(mark[ p ] == ck) return true;
			ck++;
		}
		return false;
	}
};
