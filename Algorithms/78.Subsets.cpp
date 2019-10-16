class Solution {
    vector<vector<int>> ret;
    vector<int> n;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0) {
            ret.assign(1, vector<int>());
            return ret;
        }
        n = nums;
        solve(0, nums.size() - 1);
        return ret;
    }
    void solve(int num, int p) {
        if(p == -1) {
            vector<int> v;
            for(int i = 0; i < n.size(); i++)
                if(check(num, i)) v.push_back(n[i]);
            ret.push_back(v);
            return;
        }
        solve(bitOn(num, p), p - 1);
        solve(num, p - 1);
    }
    bool check(int num, int p) {
        return num & (1 << p);
    }
    int bitOn(int num, int p) {
        return num | (1 << p);
    }
};
