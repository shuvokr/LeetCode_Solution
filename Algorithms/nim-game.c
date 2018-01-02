// https://leetcode.com/problems/nim-game/description/

bool canWinNim(int n) { return !(n == ((n >> 2) << 2)); }
