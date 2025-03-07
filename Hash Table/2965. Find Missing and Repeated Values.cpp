// 2025/03/06
class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid[0].size();
            vector<bool> appear(n * n + 1, false);
            vector<int> ans(2);
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    if(appear[grid[i][j]]) ans[0] = grid[i][j];
                    appear[grid[i][j]] = true;
                }
            }
            for(int i = 1; i < appear.size(); ++i){
                if(!appear[i]) {
                    ans[1] = i;
                    break;
                }
            }
            return ans;
        }
    };