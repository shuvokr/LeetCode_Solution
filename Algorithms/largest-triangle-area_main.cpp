https://leetcode.com/problems/largest-triangle-area/description/

class Solution {
public:
    template <class T> T sq(T x) {return x * x;}
    template <class T> T cordinatlenth(T a, T b, T c, T d) { return sqrt( sq(a - c) + sq(b - d) ); }
    double largestTriangleArea(vector<vector<int>>& points) {
        double ret = 0.0, mxarea = 0.0, a, b, c, s, area;
        int len = points.size();
        for(int i = 0; i < len; i++)
            for(int j = i + 1; j < len; j++)
                for(int k = j + 1; k < len; k++)
                {
                    a = cordinatlenth((double)points[i][0], (double)points[i][1], (double)points[j][0], (double)points[j][1]);
                    b = cordinatlenth((double)points[i][0], (double)points[i][1], (double)points[k][0], (double)points[k][1]);
                    c = cordinatlenth((double)points[k][0], (double)points[k][1], (double)points[j][0], (double)points[j][1]);
                    bool mark = false;
                    if(a > b && a > c && b + c > a) mark = true;
                    else if(b > a && b > c && a + c > b) mark = true;
                    else if(c > b && c > a && b + a > c) mark = true;
                    if(mark)
                    {
                        s = (a + b + c) / 2.0;
                        area = sqrt(s*(s-a)*(s-b)*(s-c));
                        mxarea = area - mxarea > 0.0 ? area : mxarea;
                    }
                }
        return mxarea;
    }
};
