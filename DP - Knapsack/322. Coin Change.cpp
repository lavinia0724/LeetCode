// 2026/05/03
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = 1e9;
        vector<int> dp(amount+1, INF);

        dp[0] = 0;
        
        for(auto coin: coins){
            for(int j = coin; j <= amount; ++j){
                dp[j] = min(dp[j], dp[j-coin] + 1);
            }
        }
        return (dp[amount] == INF) ? -1 : dp[amount];
    }
};