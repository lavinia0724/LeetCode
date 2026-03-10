// 2026/03/10
class Solution {
public:
    const int MOD = 1e9 + 7;

    int numberOfStableArrays(int zero, int one, int limit) {

        vector<vector<long long>> dp0(zero + 1, vector<long long>(one + 1));
        vector<vector<long long>> dp1(zero + 1, vector<long long>(one + 1));
        // dp0[i][j]
        // 用了 i 個 0
        // 用了 j 個 1
        // 最後一個數字是 0

        for (int i = 1; i <= min(zero, limit); i++) dp0[i][0] = 1; // 0、00、000 都合法

        for (int j = 1; j <= min(one, limit); j++) dp1[0][j] = 1;

        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                // dp1[i-k][j]: 代表前面用了 (i-k) 個 0，前面用了 j 個 1，最後是 1
                dp0[i][j] = (dp0[i-1][j] + dp1[i-1][j]) % MOD;
                if (i - limit - 1 >= 0) dp0[i][j] = (dp0[i][j] - dp1[i-limit-1][j] + MOD) % MOD; // 扣掉那些「出現 limit+1 個連續 0」的非法排列

                dp1[i][j] = (dp1[i][j-1] + dp0[i][j-1]) % MOD;
                if (j - limit - 1 >= 0) dp1[i][j] = (dp1[i][j] - dp0[i][j-limit-1] + MOD) % MOD;
            }
        }

        return (dp0[zero][one] + dp1[zero][one]) % MOD;
    }
};