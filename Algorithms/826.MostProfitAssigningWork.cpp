class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ret = 0;
        vector<pair<int, int>> v;
        for(int i = 0; i < difficulty.size(); i++) {
            pair<int, int> pi = make_pair(difficulty[i], profit[i]);
            v.push_back(pi);
        }
        sort(v.begin(), v.end());
        sort(worker.begin(), worker.end());
        
        int maxP = 0, j = 0;
        
        for(int i = 0; i < worker.size(); i++) {
            while(j < v.size() && worker[i] >= v[j].first) {
                if(maxP < v[j].second)
                    maxP = v[j].second;
                j++;
            }
            if(j == v.size()) {
                ret += maxP * (worker.size() - i);
                i = worker.size();
            }
            else {
                ret += maxP;
            }
        }
        
        return ret;
    }
};
