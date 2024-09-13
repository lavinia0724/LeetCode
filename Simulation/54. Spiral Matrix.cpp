// 2024/09/13
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans(m * n, -1);

        int step[4][4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 右下左上 順時針
        int direction = 0, rowNow = 0, colNow = 0;

        for(int i = 0; i < m * n; ++i){
            ans[i] = matrix[rowNow][colNow];
            matrix[rowNow][colNow] = -101;

            int rowNext = rowNow + step[direction][0];
            int colNext = colNow + step[direction][1];
            
            if(rowNext >= m || rowNext < 0 || colNext >= n || colNext < 0 || matrix[rowNext][colNext] == -101) {
                direction = (direction + 1) % 4;
                rowNext = rowNow + step[direction][0];
                colNext = colNow + step[direction][1];
            }
            
            rowNow = rowNext;
            colNow = colNext;
        }
        return ans;
    }
};