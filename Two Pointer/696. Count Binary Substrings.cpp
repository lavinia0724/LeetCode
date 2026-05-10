// 2026/05/10
class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0; // 前一段連續相同字元的長度
        int cur = 1;  // 目前這一段連續相同字元的長度
        int ans = 0;

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) { // 還在同一段，例如 00 或 111
                cur++;
            } else {
                // 字元改變，代表目前這一段結束了
                // 可以拿「前一段」和「目前段」配對
                ans += min(prev, cur);

                // 目前段變成下一輪的前一段
                prev = cur;

                // 新的一段從 s[i] 開始，長度是 1
                cur = 1;
            }
        }

        // 最後一段不會再遇到字元改變，所以要手動結算一次
        ans += min(prev, cur);

        return ans;
    }
};