/* 2024/05/12 */
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size()-2;
        vector<vector<int>> ans(n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int maxnum = 0;
                for(int k = i; k < i + 3; ++k){
                    for(int p = j; p < j + 3; ++p){
                        maxnum = max(maxnum, grid[k][p]);
                    }
                }
                ans[i].push_back(maxnum);
            }
        }
        return ans;
    }
};