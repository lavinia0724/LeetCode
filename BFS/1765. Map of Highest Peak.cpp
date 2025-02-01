// 2025/01/23
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> adjacentCellHeight(isWater.size(), vector<int>(isWater[0].size(), -1));

        int steps[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        queue<pair<int, int>> cells;
        for(int i = 0; i < isWater.size(); ++i){
            for(int j = 0; j < isWater[0].size(); ++j){
                if(isWater[i][j] == 1) {
                    cells.push({i, j});
                    adjacentCellHeight[i][j] = 0;
                }
            }
        }


        while(!cells.empty()){
            auto top = cells.front();
            cells.pop();

            for(int i = 0; i < 4; ++i){
                int nextRow = top.first + steps[i][0];
                int nextCol = top.second + steps[i][1];

                if(nextRow < 0 || nextRow >= isWater.size() || nextCol < 0 || nextCol >= isWater[0].size()) continue;

                if(adjacentCellHeight[nextRow][nextCol] == -1){
                    adjacentCellHeight[nextRow][nextCol] = adjacentCellHeight[top.first][top.second] + 1;
                    cells.push({nextRow, nextCol});
                }
            }

        }

        return adjacentCellHeight;
    }
};