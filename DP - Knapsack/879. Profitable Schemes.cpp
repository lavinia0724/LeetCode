// 2026/05/03
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<long long int>> dp(n+1 , vector<long long int>(minProfit+1, 0)); // dp[g][p] = 用 g 個人，達到 profit 至少 p 的方案數
        const int mod = 1e9 + 7;

        dp[0][0] = 1;

        for(int i = 0; i < group.size(); ++i){  // group.size() == profit.size() 一樣的
            int members = group[i];
            int earn = profit[i];

            for(int g = n; g >= members; --g){ // dp 第一維是 group，第二維是 profit，所以 for 第二圈從 group 開始更新
                for(int p = minProfit; p >= 0; --p){
                    long long int newProfit = min(minProfit, p + earn);
                    dp[g][newProfit] = (dp[g][newProfit] + dp[g - members][p]) % mod; // 這題是找方法數問題，用 +=
                }
            }
        }

        long long int ans = 0;
        for(int g = 0; g <= n; ++g){
            ans = (ans + dp[g][minProfit]) % mod;
        }
        return ans;
    }
};