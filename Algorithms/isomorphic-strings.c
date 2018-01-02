// https://leetcode.com/problems/isomorphic-strings/description/

bool isIsomorphic(char* s, char* t) {
    bool res = true;
    short int mapValue[ 131 ], mapValue1[ 131 ];
    for(int i = 0; i < 131; i++) mapValue[i] = mapValue1[i] = 0;
    for(int i = 0, len = strlen(s), u = s[i], v = t[i]; res && i < len; i++, u = s[i], v = t[i])
    {
        mapValue[u] = !mapValue[u] || mapValue[u] == v ? v : 0;
        mapValue1[v] = !mapValue1[v] || mapValue1[v] == u ? u : 0;
        res = mapValue[u] && mapValue1[v];
    }
    return res;
}
