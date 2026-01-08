// 2026/01/08
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n); // u 能走到誰
        vector<int> indeg(n, 0); // (入度) v 有幾條邊指進來

        // 建圖
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }

        // Kahn’s Algorithm，q 紀錄起點
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) q.push(i); // 所有 入度為 0 的點 都可以當起點
        }

        int ans = 0;
        int visited = 0;
        vector<vector<int>> dp(n, vector<int>(26, 0)); // 26 種顏色

        // Topological Sort
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            visited++;

            int color = colors[u] - 'a';
            dp[u][color]++; // 走到節點 u，它自己的顏色出現一次

            ans = max(ans, dp[u][color]);

            // u → v 
            for (int v : graph[u]) { // 對 所有 u 能走到的節點 v
                for (int c = 0; c < 26; c++) {
                    // 所有能走到 u 的最佳路徑，都可以延伸到 v
                    // u 累積到的所有顏色次數，都可以當成 v 的候選答案
                    // dp[v][c]: 原本的 dp[v][c]
                    // dp[u][c]: 從 u 來的 dp[u][c]
                    dp[v][c] = max(dp[v][c], dp[u][c]);
                }

                // indeg[v]: 還有幾個前置節點沒處理
                indeg[v]--; // u 已經處理完
                if (indeg[v] == 0) q.push(v); // v 的所有前置節點都處理完了，現在 v 可以進 queue
            }

        }
        if (visited != n) return -1; // vis 超過 n 次代表有環
        return ans;
    }
};