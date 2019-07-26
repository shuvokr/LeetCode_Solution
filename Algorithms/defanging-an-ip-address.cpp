// Link: https://leetcode.com/problems/defanging-an-ip-address/

class Solution {
public:
    string defangIPaddr(string address) {
        string result = "";
        int len = address.size();
        for(int i = 0; i < len; i++)
            if(address[i] == '.') result = result + "[.]";
            else result = result + address[i];
        return result;
    }
};
