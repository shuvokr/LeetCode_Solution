class Solution {
public:
    int dayOfYear(string date) {
        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> v;
        char *tok;
        char *str = const_cast<char*>(date.c_str());
        tok = strtok(str, "-");
        while(tok != NULL) {
            v.push_back(atoi(tok));
            tok = strtok(NULL, "-");
        }
        int totalDate = v[2];
        for(int i = 1; i < v[1]; i++)
            totalDate += daysInMonth[i];
        totalDate += v[1] > 2 && isLeepYear(v[0]) ? 1 : 0;
        
        return totalDate;
    }
    bool isLeepYear(int year) {
        if (year % 400 == 0) return true;
        if(year % 100 == 0) return false;
        if(year % 4 == 0) return true;
        return false;
    }
};
