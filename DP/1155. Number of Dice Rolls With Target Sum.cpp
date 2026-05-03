// 2026/05/03
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long int>> dp(n+1, vector<long long int>(target+1, 0)); // dp[n][k] 第一維是用了多少個少子，第二維是骰子面的值
        const int mod = 1e9 + 7;

        dp[0][0] = 1;

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= k; ++j){
                for(int now = target; now >= j; --now){
                    dp[i][now] = (dp[i][now] + dp[i-1][now - j]) % mod;
                }
            }
        }

        return dp[n][target];
    }
};