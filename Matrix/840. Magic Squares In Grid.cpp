// 2024/08/09
class Solution {
public:
    bool isMagicSquare_Clockwise(vector<vector<int>>& grid, int row, int col){
        int step[4][4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // 順時針
        int checkClockwise[] = {2, 9, 4, 3, 8, 1, 6, 7};
        int *firstElement = find(checkClockwise, checkClockwise + 8, grid[row-1][col-1]);

        if(firstElement == checkClockwise + 8) return false; // 左上角數字不是這八個數字，必不是 magic square
        int checkElement = firstElement - checkClockwise; // 從記憶體位址轉索引值

        int nowRow = row-1, nowCol = col-1;
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 2; ++j){
                if(grid[nowRow][nowCol] != checkClockwise[checkElement]) return false;

                nowRow += step[i][0];
                nowCol += step[i][1];
                checkElement = (checkElement + 1) % 8;
            }
        }

        return true;
    }

    bool isMagicSquare_checkCounterclockwise(vector<vector<int>>& grid, int row, int col){
        int step[4][4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // 逆時針
        int checkCounterclockwise[] = {7, 6, 1, 8, 3, 4, 9, 2};
        int *firstElement = find(checkCounterclockwise, checkCounterclockwise + 8, grid[row-1][col-1]);

        if(firstElement == checkCounterclockwise + 8) return false; // 左上角數字不是這八個數字，必不是 magic square
        int checkElement = firstElement - checkCounterclockwise; // 從記憶體位址轉索引值

        int nowRow = row-1, nowCol = col-1;
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 2; ++j){
                if(grid[nowRow][nowCol] != checkCounterclockwise[checkElement]) return false;

                nowRow += step[i][0];
                nowCol += step[i][1];
                checkElement = (checkElement + 1) % 8;
            }
        }
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 1; i + 1 < grid.size(); ++i){
            for(int j = 1; j + 1 < grid.size(); ++j){
                if(grid[i][j] == 5){
                    if(isMagicSquare_Clockwise(grid, i, j) || isMagicSquare_checkCounterclockwise(grid, i, j)) ans++;
                }
            }
        }
        return ans;
    }
};