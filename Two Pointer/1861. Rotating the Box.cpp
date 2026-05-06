// 2026/05/06
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        int ptr1 = m - 1, ptr2 = m - 1;

        for(int i = 0; i < m; ++i){
            for(int j = n-1; j >= 0; --j){ // 由右往左搜尋每一層
                if(boxGrid[i][j] == '*') continue;
                if(boxGrid[i][j] == '#') continue;

                // 如果 boxGrid[i][j] 是空格才會進來這裡
                for(int k = j-1; k >= 0; --k){ // 由右往左搜尋去搜 j 的左邊有沒有要跟他交換位置的
                    if(boxGrid[i][k] == '*'){
                        j = k;
                        break;
                    }
                    if(boxGrid[i][k] == '#') {
                        swap(boxGrid[i][k], boxGrid[i][j]);
                        break;
                    }
                }

            }
        }

        vector<vector<char>> ans(n, vector<char>(m));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                ans[i][m-j-1] = boxGrid[j][i];
            }
        }
        return ans;
    }
};