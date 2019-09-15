class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> Q;
        for(int i = 0; i < stones.size(); i++)
            Q.push(stones[i]);
        while(Q.size() > 1) {
            int y = Q.top();
            Q.pop();
            int x = Q.top();
            Q.pop();
            
            y -= x;
            Q.push(y);
        }
        return Q.top();
    }
};
