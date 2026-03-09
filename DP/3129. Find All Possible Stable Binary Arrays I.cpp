// 2026/03/09
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;

        vector<vector<long long>> dp0(zero + 1, vector<long long>(one + 1));
        vector<vector<long long>> dp1(zero + 1, vector<long long>(one + 1));
        // dp0[i][j] 代表
        // 用了 i 個 0
        // 用了 j 個 1
        // 最後一個數字是 0 有幾種排列方法

        dp0[0][0] = 1;
        dp1[0][0] = 1;

        for (int i = 0; i <= zero; i++) { // 嘗試所有可能的狀態
            for (int j = 0; j <= one; j++) {
                // 情況 A：最後放 0
                
                // 把所有 <= limit 的可能性加起來
                for (int k = 1; k <= limit && k <= i; k++) {
                    // dp1[i-k][j]: 代表前面用了 (i-k) 個 0，前面用了 j 個 1，最後是 1
                    dp0[i][j] = (dp0[i][j] + dp1[i-k][j]) % MOD;
                }
                
                // 情況 B：最後放 1
                
                for (int k = 1; k <= limit && k <= j; k++) {
                    dp1[i][j] = (dp1[i][j] + dp0[i][j-k]) % MOD;
                }
                
            }
        }

        return (dp0[zero][one] + dp1[zero][one]) % MOD; // 用了 zero 個 0 one 個 1 最後尾數是 0 或 1 的兩種情況加起來
    }
};