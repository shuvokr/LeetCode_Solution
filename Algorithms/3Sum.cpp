//Problem description: https://leetcode.com/problems/3sum
class Solution 
{
public:
	typedef vector<int> vi;
	int ret[ 100000 ][ 3 ];
	map <int, int> pp, nn;
    vector<vi> threeSum(vector<int>& nums) 
	{
		pp.clear(); nn.clear();
		
        vector <int> neg, pos;
        int zero = 0, len = nums.size(), ind = 0;
        
        for(int i = 0; i < len; i++)
        	if(nums[ i ] == 0) zero++;
        	else if(nums[ i ] > 0) pos.push_back(nums[ i ]);
        	else neg.push_back((-1) * nums[ i ]);
        
        vector <int> x = pos, y = neg;
        
        for(int i = 0; i < x.size(); i++) pp[ x[ i ] ]++; 
        for(int i = 0; i < y.size(); i++) nn[ y[ i ] ]++;
        
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        
        pos.erase(unique(pos.begin(), pos.end()), pos.end());
        neg.erase(unique(neg.begin(), neg.end()), neg.end());
        
        for(int i = 0; i < pos.size(); i++) cout << pos[ i ] << " "; puts("");
        for(int i = 0; i < neg.size(); i++) cout << neg[ i ] << " "; puts("");
        
        if( zero )
        {
        	if(pos.size() && neg.size())
        	for(int i = 0; i < pos.size(); i++)
        	{
        		if(nn.find(pos[ i ]) != nn.end())
        		{
        			ret[ ind ][ 0 ] = 0;
        			ret[ ind ][ 1 ] = pos[ i ];
        			ret[ ind ][ 2 ] = (-1) * pos[ i ];
        			ind++;
				}
			}
		}
		
		if(pos.size() && neg.size())
		for(int i = 0; i < pos.size() - 1; i++)
			for(int j = i + 1; j < pos.size(); j++)
			{
				int target = pos[ i ] + pos[ j ];
				if(nn.find(target) != nn.end())
	        	{
	        		ret[ ind ][ 0 ] = pos[ j ];
	        		ret[ ind ][ 1 ] = pos[ i ];
	        		ret[ ind ][ 2 ] = (-1) * target;
	        		ind++;
	      }
			}
		for(int i = 0; i < pos.size(); i++)
		{
			if(pp[ pos[ i ] ] > 1 && nn.find(pos[ i ] + pos[ i ]) != nn.end())
			{
				ret[ ind ][ 0 ] = pos[ i ];
	        	ret[ ind ][ 1 ] = pos[ i ];
	        	ret[ ind ][ 2 ] = (-1) * (pos[ i ] << 1);
	        	ind++;
			}
		}
			
		vector <int> tmp;
		tmp = pos;
		pos = neg;
		neg = tmp;
		
		if(pos.size() && neg.size())
		for(int i = 0; i < pos.size() - 1; i++)
			for(int j = i + 1; j < pos.size(); j++)
			{
				int target = pos[ i ] + pos[ j ];
				if(pp.find(target) != pp.end())
	      {
	        		ret[ ind ][ 0 ] = (-1) * pos[ j ];
	        		ret[ ind ][ 1 ] = (-1) * pos[ i ];
	        		ret[ ind ][ 2 ] = target;
	        		ind++;
	      }
			}
		for(int i = 0; i < pos.size(); i++)
		{
			if(nn[ pos[ i ] ] > 1 && pp.find(pos[ i ] + pos[ i ]) != pp.end())
			{
				ret[ ind ][ 0 ] = (-1) * pos[ i ];
	        	ret[ ind ][ 1 ] = (-1) * pos[ i ];
	        	ret[ ind ][ 2 ] = (pos[ i ] << 1);
	        	ind++;
			}
		}
		
		vector <vi> sk;
		int s = 0;
		if(zero > 2)
		{
		  ind++;
			sk.assign(ind, vi());
			sk[ s ].push_back( 0 );
			sk[ s ].push_back( 0 );
			sk[ s ].push_back( 0 );
			s++;
		}
		else sk.assign(ind, vi());
		
		for(int i = s; i < ind; i++) 
		{
			sk[ i ].push_back(ret[ i - s ][ 0 ]);
			sk[ i ].push_back(ret[ i - s ][ 1 ]);
			sk[ i ].push_back(ret[ i - s ][ 2 ]);
			sort(sk[i].begin(), sk[i].end());
		}
		sort(sk.begin(), sk.end());
		return sk;
    }
};
