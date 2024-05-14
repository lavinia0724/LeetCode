/* 2024/05/14 */
class Solution {
public:
    bool visited[20][20];
    int step[4][4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(int nowi, int nowj, vector<vector<int>>& grid, int maxi, int nowgold){
        nowgold += grid[nowi][nowj];
        maxi = max(maxi, nowgold);

        for(int i = 0; i < 4; ++i){
            int nexti = nowi + step[i][0];
            int nextj = nowj + step[i][1];

            if(nexti < 0 || nexti >= grid.size() || nextj < 0 || nextj >= grid[0].size() || visited[nexti][nextj] || grid[nexti][nextj] == 0){
                continue;
            }
            visited[nexti][nextj] = true;
            maxi = max(maxi, dfs(nexti, nextj, grid, maxi, nowgold));
            visited[nexti][nextj] = false;
        }
        return maxi;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        memset(visited, false, sizeof(visited));

        int maxi = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[i].size(); ++j){
                if(grid[i][j] != 0){
                    visited[i][j] = true;
                    maxi = max(maxi, dfs(i, j, grid, 0, 0));
                    visited[i][j] = false;
                }
            }
        }
        return maxi;
    }  
};