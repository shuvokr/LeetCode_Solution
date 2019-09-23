class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) 
            return 0;
        
        int ret = 0;
        priority_queue<int>q;
        
        for(int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
        }
        while(q.size() > 1) {
            int a = q.top(); q.pop();
            int b = q.top(); 
            a -= b;
            ret = ret < a ? a : ret;
        }
        return ret;
    }
};
