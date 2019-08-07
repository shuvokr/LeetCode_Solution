// Link : https://leetcode.com/problems/valid-boomerang

class Solution {
    func isBoomerang(_ points: [[Int]]) -> Bool {
        if(points[0][0] == points[1][0] && points[0][0] == points[2][0]) {
            return false
        }
        if(points[0][1] == points[1][1] && points[0][1] == points[2][1]) {
            return false
        }
        if(points[0][0] - points[1][0] == points[1][0] - points[2][0] &&
          points[0][1] - points[1][1] == points[1][1] - points[2][1]) {
            return false
        }
        if(points[0] == points[1] || points[1] == points[2] || points[0] == points[2]) {
            return false
        }
        return true
    }
}
