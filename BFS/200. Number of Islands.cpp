// 2026/05/08
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        int ans = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    ans++;
                    grid[i][j] = '0';
                    q.push({i, j});

                    while(!q.empty()){
                        auto [x, y] = q.front();
                        q.pop();

                        for(int k = 0; k < 4; ++k){
                            int nextx = x + dx[k];
                            int nexty = y + dy[k];

                            if(nextx < 0 || nextx >= m || nexty < 0 || nexty >= n) continue;

                            if(grid[nextx][nexty] == '1'){
                                grid[nextx][nexty] = '0';
                                q.push({nextx, nexty});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};