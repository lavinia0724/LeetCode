// 2025/03/28
class Solution {
    public:
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            priority_queue<int, vector<int>, greater<int>> pqQueries;
            for(auto query: queries) pqQueries.push(query);
    
            unordered_map<int, int> queryNumPoint;
            priority_queue<Node> pqGrid;
            vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), false));
    
            int pointsNow = 0, queryNumNow = pqQueries.top();
    
            pqGrid.push({grid[0][0], 0, 0});
            visited[0][0] = true;
            bool check = false;
            while(!pqGrid.empty()){
                auto nowNode = pqGrid.top();
                pqGrid.pop();
    
                while(nowNode.value >= queryNumNow) {
                    queryNumPoint[queryNumNow] = pointsNow;
    
                    if(pqQueries.empty()){
                        check = true;
                        break;
                    }
                    pqQueries.pop(); // 變成先 pop，因為是先取 top 的值再做確認，確認完畢現在才能 pop
                    queryNumNow = pqQueries.top();
                }
                if(check) break;
                
                pointsNow += 1;
    
                for(int i = 0; i < 4; ++i){
                    int nextRow = nowNode.row + step[i][0];
                    int nextCol = nowNode.col + step[i][1];
    
                    if(nextRow < 0 || nextRow >= grid.size() || nextCol < 0 || nextCol >= grid[0].size() || visited[nextRow][nextCol]) continue;
                    visited[nextRow][nextCol] = true;
                    pqGrid.push({grid[nextRow][nextCol], nextRow, nextCol});
                }
    
                if(pqGrid.empty()) queryNumPoint[queryNumNow] = pointsNow; // 會到這代表 queryNumNow 必 > nowNode.value 且所有 grid 他都能到
            }
    
            while(!pqQueries.empty()){
                queryNumNow = pqQueries.top();
                pqQueries.pop();
                queryNumPoint[queryNumNow] = pointsNow;
            }
    
            vector<int> ans(queries.size(), 0);
            for(int i = 0; i < queries.size(); ++i){
                ans[i] = queryNumPoint[queries[i]];
            }
            return ans;
        }
    private:
        struct Node{
            int value;
            int row;
            int col;
    
            bool operator < (const Node &rhs) const{
                return value > rhs.value;
            }
        };
    
        int step[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    };