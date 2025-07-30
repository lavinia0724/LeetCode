// 2025/07/30
class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9+7;
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 5;

        vector<int> dp(n+1, 0);
        dp[1] = 1; 
        dp[2] = 2; 
        dp[3] = 5;
        for(int i = 4; i <= n; ++i){
            dp[i] = (dp[i-1] * 2LL + dp[i-3]) % MOD; // 2LL avoid int overflow
        }
        return dp[n];
    }
};

/*
dp[4] = dp[3]{|} + dp[2]{=} + dp[1]({｢｣}+{﹂﹁}) (所以要 * 2) + dp[0]({｢-｣}+{﹂-﹁})
dp[n] = dp[n-1] + dp[n-2] + 2*(dp[n-3]+...+dp[0]) <- 第一式
      = dp[n-1] + (dp[n-2] + dp[n-3]) + dp[n-3] + 2*(dp[n-4]+...+dp[0]) <- 把 2*dp[n-3] 提出來
      = dp[n-1] + (dp[n-1] - 2*(dp[n-4]+...+dp[0])) + dp[n-3] + 2*(dp[n-4]+...+dp[0])
      = 2 * dp[n-1] + dp[n-3]

-> 因為可以從第一式推得 dp[n-1] = dp[n-2] + dp[n-3] + 2*(dp[n-4]+...+dp[0])
   所以 dp[n-2] + dp[n-3] = dp[n-1] - 2*(dp[n-4]+...+dp[0])
*/