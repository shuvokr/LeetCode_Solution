//Problem Description: https://leetcode.com/problems/two-sum
class Solution 
{
    public:
    typedef pair<int, int> p;
    #define phl puts("debug")
    vector<int> twoSum(vector<int>& nums, int target) 
    {
    	vector<int> ret;
    	
    	map <int, p> mp;
    	int len = nums.size(), a, b;
    	
    	if(len == 2)
    	{
    		ret.push_back( 0 );
    		ret.push_back( 1 );
    		return ret;
		}
    	
    	for(int i = 0, tmp; i < len; i++)
    	{
    		tmp = nums[ i ];
    		if(mp.find( tmp ) == mp.end()) mp[ tmp ].first = i;
    		else mp[ tmp ].second = i;
    	}
    	
    	sort(nums.begin(), nums.end());
    	
    	bool flag = true;
    	for(int i = 0; flag; i++)
    	{
    		int tmp = target - nums[ i ];
    		int low = i + 1, high = len - 1, mid;
    		while(low <= high)
    		{
    			//cout << low << " " << high << endl;
    			mid = (low + high) >> 1;
    			if(nums[ mid ] < tmp) low = mid + 1;
    			else if(nums[ mid ] > tmp) high = mid - 1;
    			else
    			{
    				//cout << i << " " << mid << endl;
    				//cout << mp[ 2 ].first << " " << mp[ 4 ].first << endl;
    				flag = false;
    				int a = mp[ nums[ i ] ].first, b = mp[ nums[ mid ] ].first;
    				if(nums[ i ] == tmp) b = mp[ nums[ mid ] ].second;
					low += high + 1;
					//cout << a << " " << b << endl;
					ret.push_back( a );
					ret.push_back( b );
				}
			}
		}
		
		//cout << ret[ 0 ] << " " << ret[ 1 ] << endl;
		return ret;
	}
};
