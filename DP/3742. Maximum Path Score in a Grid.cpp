// 2026/04/30
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        // dp[i][j][c] = 走到格子 (i, j)，且目前總 cost 剛好是 c 時，可以得到的最大 score
        // 如果 dp[i][j][c] == -1，代表目前不存在任何一條路可以用 cost = c 走到 (i, j)
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, -1)));

        // 起點本身也要計入 cost 和 score：
        // cost：如果格子值不是 0，代表經過一個有分數的格子，cost +1
        // score：直接加上格子的值
        int startCost = (grid[0][0] == 0 ? 0 : 1); 
        int startScore = grid[0][0];

        // 如果光是起點的 cost 就超過 k，代表沒有合法路徑
        if (startCost > k) return -1;

        // 初始化：目前站在起點 (0, 0)
        dp[0][0][startCost] = startScore;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                for(int cost = 0; cost <= k; ++cost){ // 其實本質是枚舉有沒有存在的 cost 可以去試
                    if (dp[i][j][cost] == -1) continue; // 只有 dp[i][j][cost] 不是 -1，才表示真的存在一條路可以走到 (i, j)，且目前總 cost 剛好是 cost

                     int currentScore = dp[i][j][cost];

                    // 往下
                    if (i + 1 < m){
                        int nextCellValue = grid[i + 1][j];
                        int nextCost = cost; // 先繼承目前的 cost
                        if (nextCellValue != 0) nextCost += 1; // 如果下一格不是 0，表示多經過一個有分數的格子，cost +1
                        int nextScore = currentScore + nextCellValue; // score 則是直接加上下一格的值

                        // 只有 cost 不超過 k，這條路才合法
                        if (nextCost <= k) dp[i + 1][j][nextCost] = max(dp[i + 1][j][nextCost], nextScore); // 同樣走到 (i + 1, j) 且 cost 一樣時，保留 score 比較大的那條路
                    }

                    // 往右
                    if (j + 1 < n){
                        int nextCellValue = grid[i][j + 1];
                        int nextCost = cost;
                        if (nextCellValue != 0) nextCost += 1;
                        int nextScore = currentScore + nextCellValue;

                        if (nextCost <= k) dp[i][j + 1][nextCost] = max(dp[i][j + 1][nextCost], nextScore);
                    }
                }
            }
        }
        
        int ans = -1;
        // 枚舉所有 cost，找最大的 score
        for (int cost = 0; cost <= k; ++cost) {
            ans = max(ans, dp[m - 1][n - 1][cost]);
        }
        return ans;
    }
};