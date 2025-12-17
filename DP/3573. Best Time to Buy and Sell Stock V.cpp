// 2025/12/17
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const long long NEG = -1e18;
        int n = prices.size();
        vector<vector<long long>> dp(k + 1, vector<long long>(3, NEG));
        dp[0][0] = 0;

        for (int price : prices) {
            auto prev = dp;

            for (int t = 0; t <= k; t++) {
                // stay flat
                dp[t][0] = max(dp[t][0], prev[t][0]);
                // flat -> long
                dp[t][1] = max(dp[t][1], prev[t][0] - price);
                // flat -> short
                dp[t][2] = max(dp[t][2], prev[t][0] + price);

                if (t < k) {
                    // long -> flat (sell)
                    dp[t + 1][0] = max(dp[t + 1][0], prev[t][1] + price);

                    // short -> flat (buy back)
                    dp[t + 1][0] = max(dp[t + 1][0], prev[t][2] - price);
                }
            }
        }

        long long ans = 0;
        for (int t = 0; t <= k; t++)
            ans = max(ans, dp[t][0]);

        return ans;
    }
};

/*
空手（flat）
持有股票（long）long：買 → 賣
放空中（short）short：賣 → 買回

flat -> long
利潤 -= p
long -> flat
利潤 += p, 交易數 +1

flat -> short
利潤 += p
short -> flat
利潤 -= p, 交易數 +1
*/