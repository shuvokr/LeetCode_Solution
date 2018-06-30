// Link: https://leetcode.com/problems/rotated-digits/description/

class Solution {
public:
    int rotatedDigits(int N) {
        int answer = 0; N++;
        for(int i = 1; i < N; i++)
        {
            bool a = false, b = true;
            for(int j = i, x; j && b; j /= 10)
            {
                x = j % 10;
                a = x == 2 || x == 5 || x == 6 || x == 9 ? true : a;
                b = x == 3 || x == 4 || x == 7 ? false : b;
            }
            answer += (a && b);
        }
        return answer;
    }
};
