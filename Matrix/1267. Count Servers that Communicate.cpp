// 2025/01/23
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;

        int row[grid.size()], col[grid[0].size()];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));

        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    row[i]++;
                    col[j]++;
                }
            }
        }

        for(int i = 0; i < grid.size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j)
                if(grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) ans++;

        return ans;
    }
};