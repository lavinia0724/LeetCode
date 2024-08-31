// 2024/08/28
class Solution {
public:
    int step[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void dfs(int rowNow, int colNow, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited, bool& check){
        for(int i = 0; i < 4; ++i){
            int rowNext = rowNow + step[i][0];
            int colNext = colNow + step[i][1];

            // 超出邊界 continue
            if(rowNext < 0 || rowNext >= grid2.size() || colNext < 0 || colNext >= grid2[0].size()) continue;

            // 一定只有 grid2[rowNext][colNext] == 1 && grid1[rowNext][colNext] == 1 才繼續 dfs
            if(!grid1[rowNext][colNext] && grid2[rowNext][colNext]) check = true; // 當 grid2 是陸地，grid1 是海，這塊連接地必不符合

            // grid2 不是陸地、已拜訪過都 continue
            if(!grid2[rowNext][colNext] || visited[rowNext][colNext]) continue;

            visited[rowNext][colNext] = true;
            dfs(rowNext, colNext, grid1, grid2, visited, check);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<bool>> visited(grid2.size(), vector<bool>(grid2[0].size(), false));
        
        // 只要對 grid2 判斷區塊，grid1 用來判斷是否也有重疊，有就 +1
        int ans = 0;
        for(int i = 0; i < grid2.size(); ++i){
            for(int j = 0; j < grid2[0].size(); ++j){
                if(grid2[i][j] && grid1[i][j] && !visited[i][j]){
                    bool check = false;
                    dfs(i, j, grid1, grid2, visited, check);
                    if(!check){
                        ans++;
                    }

                }
            }
        }
        return ans;
    }
};