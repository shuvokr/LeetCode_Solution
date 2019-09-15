class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        
        int lens1 = s1.size();
        int mark[123], flag[123];
        
        for(int i = 97; i < 123; i++)
            mark[i] = 0;
        for(int i = 0; i < lens1; i++) 
            mark[ s1[i] ]++;
        
        for(int i = 0; i < s2.size() - lens1 + 1; i++) {
            
            for(int j = 97; j < 123; j++)
                flag[j] = 0;
            for(int j = i; j < i + lens1; j++)
                flag[ s2[j] ]++;
            
            bool check = true;
            for(int j = 97; j < 123; j++)
                if(flag[j] != mark[j]) {
                    check = false;
                    j = 123;
                }
            
            if(check) return true;
        }
        
        return false;
    }
};
