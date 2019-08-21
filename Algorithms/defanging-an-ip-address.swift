// Link : https://leetcode.com/problems/defanging-an-ip-address

class Solution {
    func defangIPaddr(_ address: String) -> String {
        var ret = String();
        for (index, char) in address.enumerated() {
            if(char == ".") {
                ret = ret + "[.]";
            }
            else {
                ret = ret + String(char);
            }
        }
        return ret;
    }
}
