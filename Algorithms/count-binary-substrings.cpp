// Link: https://leetcode.com/problems/count-binary-substrings/description/

class Solution {
public:
    int countBinarySubstrings(string S) {
        int one = 0, zero = 0, answer = 0, len = S.size();
        bool mark = S[0] == '0' ? false : true;
        for(int i = 0;i < len;)
        {
            if(mark)
            {
                for(;S[i] == '1';i++) one++;
                answer += one < zero ? one : zero;
                mark = false; zero = 0;
            }
            else
            {
                for(;S[i] == '0';i++) zero++;
                answer += one < zero ? one : zero;
                mark = true; one = 0;
            }
        }
        return answer;
    }
};
