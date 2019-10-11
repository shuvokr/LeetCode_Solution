class Solution {
public:
    struct Data {
        int sum;
    };
    Data tree[80001];
    vector<int> ret;
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        init(1, 1, n);
        for(int i = 0; i < bookings.size(); i++) {
            update(1, 1, n, bookings[i][0], bookings[i][1], bookings[i][2]);
        }
        
        query(1, 1, n, 0);
        return ret;
    }
    void init(int node, int begin, int end) {
        if(begin == end) {
            tree[node].sum = 0;
            return;
        }
        
        int left = node << 1, right = left + 1, mid = (begin + end) >> 1;
        init(left, begin, mid);
        init(right, mid + 1, end);
    }
    void update(int node, int begin, int end, int L, int R, int val) {
        if(begin > R || end < L) return;
        if(begin >= L && end <= R) {
            tree[node].sum += val;
            return;
        }
        
        int left = node << 1, right = left + 1, mid = (begin + end) >> 1;
        update(left, begin, mid, L, R, val);
        update(right, mid + 1, end, L, R, val);
    }
    void query(int node, int begin, int end, int sum) {
        if(begin == end) {
            ret.push_back(sum + tree[node].sum);
            return;
        }
        
        int left = node << 1, right = left + 1, mid = (begin + end) >> 1;
        query(left, begin, mid, tree[node].sum + sum);
        query(right, mid + 1, end, tree[node].sum + sum);
    }
};
