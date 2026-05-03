// 2026/05/03
class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<long long int> dp(n+1, 0);
        const int mod = 1e9 + 7;

        dp[0] = 1;

        for(int i = 1; i <= n; ++i){
            long long int nx = pow(i, x);
            for(int j = n; j >= nx; --j){
                dp[j] = (dp[j] + dp[j-nx]) % mod; // 求方法數用 +=
            }
        }
        return dp[n];
    }
};