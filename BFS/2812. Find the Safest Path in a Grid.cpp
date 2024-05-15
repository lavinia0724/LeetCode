/* 2024/05/15 
   超級 Greedy 的 BFS */
class Solution {
public:
    int step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int n = grid.size();
        int SafeFactor[n][n];
        memset(SafeFactor, 0x3f3f3f3f, sizeof(SafeFactor));

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;

        /* grid = 
            0 0 1 
            0 0 0
            0 0 0
            minSafeFactor = 每個點到最近的 1 的距離
            2 1 0
            3 2 1
            4 2 2
        */
        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    SafeFactor[i][j] = 0;
                }

            }
        }
        // 用 bfs 更新比較不會浪費時間
        while(!q.empty()){
            int nowr = q.front().first;
            int nowc = q.front().second;
            q.pop();

            int s = SafeFactor[nowr][nowc];

            for(int k = 0; k < 4; ++k){
                int nextr = nowr + step[k][0];
                int nextc = nowc + step[k][1];
                // cout << nowr << " " << nowc << "  " << step[k][0] << " " << step[k][1] << "   " << nextr << " " << nextc << endl;

                if(nextr < 0 || nextr >= n || nextc < 0 || nextc >= n || SafeFactor[nextr][nextc] <= 1 + s) continue;

                SafeFactor[nextr][nextc] = 1 + s;
                q.push({nextr, nextc});
            }
        }

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({SafeFactor[0][0], {0, 0}});

        // 從 (0, 0) 開始，推他四周鄰居，然後取出 pq 裡 SafeFactor 最小的
        // 每次都要記錄當前最小的已取出的 minSafeFactor，直到拿出 (n-1, n-1)
        int minSafeFactor = 0x3f3f3f3f;
        bool visited[n][n];
        memset(visited, false, sizeof(visited));

        while(!pq.empty()){
            int nowr = pq.top().second.first;
            int nowc = pq.top().second.second;
            int nowSafeFactor = pq.top().first;
            pq.pop();

            minSafeFactor = min(minSafeFactor, nowSafeFactor);
            visited[nowr][nowc] = true;

            if(nowr == n-1 && nowc == n-1) break;

            for(int i = 0; i < 4; ++i){
                int nextr = nowr + step[i][0];
                int nextc = nowc + step[i][1];

                if(nextr < 0 || nextr >= n || nextc < 0 || nextc >= n || visited[nextr][nextc]) continue;
                
                visited[nextr][nextc] = true;
                pq.push({SafeFactor[nextr][nextc], {nextr, nextc}});
            }
        }

        return minSafeFactor;
    }
};