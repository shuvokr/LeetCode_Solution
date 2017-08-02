// https://leetcode.com/problems/range-sum-query-mutable/description/
class NumArray {
public:
    int stree[ 300004 ], len;
    vector<int> inp;
    NumArray(vector<int> nums) 
    {
        len = nums.size();
        inp = nums;
        treeInit(1, 0, len - 1);
    }
    
    void update(int i, int val) 
    {
        treeUpdate(1, 0, len - 1, i, val);
    }
    
    int sumRange(int i, int j) 
    {
        return query(1, 0, len - 1, i, j);
    }
    
    /************************************************************************/
    void treeInit(int node, int b, int e)
    {
        if(b > e) return;
        if(b == e)
        {
            stree[ node ] = inp[ b ];
            return;
        }
        int left = node * 2, right = left + 1, mid = (b + e) / 2;
        treeInit(left, b, mid);
        treeInit(right, mid + 1, e);
        stree[ node ] = stree[ left ] + stree[ right ];
    }
    
    void treeUpdate(int node, int b, int e, int pos, int val)
    {
        if(b > pos || e < pos) return;
        if(b == pos && e == pos) 
        {
            stree[ node ] = val;
            return;
        }
        int left = node << 1, right = left + 1, mid = (b + e) >> 1;
        treeUpdate(left, b, mid, pos, val);
        treeUpdate(right, mid + 1, e, pos, val);
        stree[ node ] = stree[ left ] + stree[ right ];
    }
    
    int query(int node, int b, int e, int low, int high)
    {
        if(b > high || e < low) return 0;
        if(b >= low && e <= high) return stree[ node ];
        int left = node << 1, right = left + 1, mid = (b + e) >> 1;
        return query(left, b, mid, low, high) + query(right, mid + 1, e, low, high);
    }
    
    /************************************************************************/
};
