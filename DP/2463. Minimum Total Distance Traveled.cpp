// 2026/04/14
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // 最佳解一定可以做到不交叉分配，最佳解應該會是每個 factory 負責一段連續的 robots
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();
        const long long INF = 1e18; // 不能直接用 LLONG_MAX 會爆掉

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INF));
        for(int j = 0; j <= m; ++j) dp[0][j] = 0; // 如果沒有 robot 要修，不管有幾間工廠，成本都是 0

        // 第 j 輪表示我們正在考慮第 j 間工廠（實際 index 是 j-1）
        for (int j = 1; j <= m; j++) {
            int pos = factory[j - 1][0]; // pos：工廠位置
            int limit = factory[j - 1][1]; // limit：工廠容量

            for (int i = 1; i <= n; i++) { // 考慮「前 i 個 robots」的最優解
                dp[i][j] = dp[i][j - 1]; // 不使用第 j 間工廠修理任何 robot

                long long cost = 0;

                // 讓第 j 間工廠修理最後 k 個 robots
                for (int k = 1; k <= min(i, limit); k++) {
                    cost += abs((long long)robot[i - k] - pos); // 把最後 k 個 robots 全部分給這間工廠的成本累加起來
                    // dp[i - k][j - 1] 意思是前 i-k 個 robots 用前 j-1 間工廠搞定
                    // cost 意思是 最後 k 個 robots 給第 j 間工廠
                    dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + cost);
                }
            }
        }

        return dp[n][m];
    }
};