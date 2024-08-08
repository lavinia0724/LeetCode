// 2024/08/08
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int step[4][4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 右下左上 順時針
        int direction = 0; // 控制現在上下左右
        int cnt = 1; // 控制這層要走多少步，每種步伐走兩個方向

        while(ans.size() < (rows * cols)){
            for(int i = 0; i < 2; ++i){
                for(int j = 0; j < cnt; ++j){
                    if(rStart < rows && rStart >= 0 && cStart < cols && cStart >= 0){
                        ans.push_back({rStart, cStart});
                    }

                    rStart += step[direction][0];
                    cStart += step[direction][1];
                }
                direction = (direction + 1) % 4;
            }
            cnt++;
        }
        return ans;
    }
};