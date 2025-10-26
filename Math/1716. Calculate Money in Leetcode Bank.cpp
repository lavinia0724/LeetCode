// 2025/10/26
class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        ans += 28 * (n / 7);
        for(int i = 1; i < n / 7; ++i) ans += 7 * i;
        for(int i = 1; i <= n % 7; ++i) ans += i;
        ans += (n % 7) * (n / 7);
        return ans;
    }
};