// Link : https://leetcode.com/problems/distribute-candies-to-people

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int sum = 0, count = 1, n = num_people * count++, check = (long long)((n * (n + 1)) / 2);
        while(check <= candies) {
            n = num_people * count++;
            check = (long long)((n * (n + 1)) / 2);
        }
        count--;
        n = num_people * count;
        if(candies < ((n * (n + 1)) / 2)) count--;
        vector<int> ret;
        for(int i = 1, x = count - 1; i <= num_people; i++) {
            if(count == 0) {
                ret.push_back(0);
                continue;
            }
            int val = count == 1 ? i : (count * i) + (num_people * (long long)((x * (x + 1)) / 2) );
            ret.push_back(val);
        }
        int tmp = num_people * count;
        tmp = (long long)((tmp * (tmp + 1)) / 2);
        candies -= tmp;
        cout << candies << " " << count << endl;
        for(int i = 0;  ; i++) {
            int val = (i+1) + (count * num_people);
            if(candies > val) {
                candies -= val;
                ret[i] += val;
            }
            else {
                ret[i] += candies;
                candies = 0;
            }
            if(candies == 0) break;
        }
        
        return ret;
    }
};
