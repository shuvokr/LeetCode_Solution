// Link : https://leetcode.com/problems/relative-sort-array/
// Tag : custom sort

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int mamo[1001], len = arr1.size(), tmp;
        memset(mamo, 0, sizeof mamo);
        for(int i = 0; i < len; i++) mamo[ arr1[i] ]++;
        arr1.clear(); len = arr2.size();
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < mamo[ arr2[i] ]; j++) 
                arr1.push_back(arr2[i]);
            mamo[ arr2[i] ] = 0;
        }
        for(int i = 0; i < 1001; i++) {
            if(!mamo[i]) continue;
            for(int j = 0; j < mamo[i]; j++)
                arr1.push_back(i);
        }
        return arr1;
    }
};
