//Problem Description: https://leetcode.com/problems/valid-parentheses/#/description
class Solution {
public:
    bool isValid(string s) {
        bool ret;
        stack <char> st;
        int len = s.size();
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else
            {
                if(st.size() == 0) return false;
                char ch = s[ i ], ck = st.top();
                if(ch == ')' && ck == '(') st.pop();
                else if(ch == '}' && ck == '{') st.pop();
                else if(ch == ']' && ck == '[') st.pop();
                else return false;
            }
        }
        ret = st.size() == 0 ? true : false;
        return ret;
    }
};
