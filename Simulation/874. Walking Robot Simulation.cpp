// 2024/09/04
class Solution {
public:
    int step[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<pair<int, int>, bool> mp;
        for(int i = 0; i < obstacles.size(); ++i) mp[{obstacles[i][0], obstacles[i][1]}] = true;

        int ans = 0;
        int nowRow = 0, nowCol = 0, direction = 0;
        for(int i = 0; i < commands.size(); ++i){
            if(commands[i] == -1){ // turn right
                direction = (direction + 1) % 4;
                continue;
            }
            if(commands[i] == -2){ // turn left
                direction = (direction - 1 + 4) % 4;
                continue;
            }

            int nextRow = nowRow + commands[i] * step[direction][0];
            int nextCol = nowCol + commands[i] * step[direction][1];

            if(direction == 0 || direction == 2){ // north or south
                if(nowCol <= nextCol){
                    for(int i = nowCol+1; i <= nextCol; ++i){
                        if(mp.find({nextRow, i}) != mp.end()) break; // 路經中有 obstacle
                        nowRow = nextRow;
                        nowCol = i;
                    }
                }
                else{
                    for(int i = nowCol-1; i >= nextCol; --i){
                        if(mp.find({nextRow, i}) != mp.end()) break; // 路經中有 obstacle
                        nowRow = nextRow;
                        nowCol = i;
                    }
                }
            }
            else{
                if(nowRow <= nextRow){
                    for(int i = nowRow+1; i <= nextRow; ++i){
                        if(mp.find({i, nextCol}) != mp.end()) break; // 路經中有 obstacle
                        nowRow = i;
                        nowCol = nextCol;
                    }
                }
                else{
                    for(int i = nowRow-1; i >= nextRow; --i){
                        if(mp.find({i, nextCol}) != mp.end()) break; // 路經中有 obstacle
                        nowRow = i;
                        nowCol = nextCol;
                    }
                }
            }

            int tmp = (pow(nowRow, 2) + pow(nowCol, 2));
            ans = max(ans, tmp);
        } 

        return ans;
    }
};