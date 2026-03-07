// 2026/03/07
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string ss = s + s;

        // alt1 = 010101010101...
        // alt2 = 101010101010...
        string alt1 = "", alt2 = "";
        for (int i = 0; i < 2 * n; i++) {
            alt1 += (i % 2 ? '1' : '0');
            alt2 += (i % 2 ? '0' : '1');
        }

        int diff1 = 0, diff2 = 0;
        int ans = INT_MAX;
        int left = 0;
        for (int right = 0; right < 2 * n; right++) {
            if (ss[right] != alt1[right]) diff1++;
            if (ss[right] != alt2[right]) diff2++;

            if (right - left + 1 > n) {
                if (ss[left] != alt1[left]) diff1--;
                if (ss[left] != alt2[left]) diff2--;
                left++;
            }

            if (right - left + 1 == n) {
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};