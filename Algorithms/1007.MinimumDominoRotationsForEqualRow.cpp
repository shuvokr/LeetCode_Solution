class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        
        int ret = INT_MAX;
        for(int i = 1; i < 7; i++) {
            ret = min(ret, solveA(A, B, i));
            ret = min(ret, solveB(A, B, i));
        }
        ret = ret == INT_MAX ? -1 : ret;
        return ret;
    }
    int solveA(vector<int> a, vector<int> b, int val) {
        int rotation = 0;
        
        for(int i = 0; i < a.size(); i++) 
            if(a[i] == val) continue;
            else if(b[i] == val) swap(a[i], b[i]), rotation++;
        
        for(int i = 0; i < a.size(); i++)
            if(a[i] != val)
                return INT_MAX;
        
        return rotation;
    }
    int solveB(vector<int> a, vector<int> b, int val) {
        int rotation = 0;
        
        for(int i = 0; i < a.size(); i++) 
            if(b[i] == val) continue;
            else if(a[i] == val) swap(a[i], b[i]), rotation++;
        
        for(int i = 0; i < a.size(); i++)
            if(b[i] != val)
                return INT_MAX;
        
        return rotation;
    }
};
