// 2026/01/04
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            int cnt = 0, sum = 0;
            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    int other = x / d;
                    if (d == other) { // 平方根
                        cnt++;
                        sum += d;
                    } else {
                        cnt += 2;
                        sum += d + other;
                    }
                    if (cnt > 4) break;
                }
            }
            if (cnt == 4) ans += sum;
        }
        return ans;
    }
};