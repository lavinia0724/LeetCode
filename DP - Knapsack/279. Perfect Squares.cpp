// 2026/05/03
class Solution {
public:
    int numSquares(int n) {
        const int INF = 1e9;
        vector<int> dp(n+1, INF);

        dp[0] = 0;

        for(int num = 1; num <= n; ++num){
            int x = sqrt(num);
            if(x * x == num){
                for(int j = num; j <= n; ++j){
                    dp[j] = min(dp[j], dp[j - num] + 1);
                }
            }
        }

        return dp[n];
    }
};