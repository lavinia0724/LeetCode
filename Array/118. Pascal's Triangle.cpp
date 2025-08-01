// 2025/08/01
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        vector<vector<int>> ans;
        ans.push_back({1});
        ans.push_back({1, 1});
        for(int i = 2; i < numRows; ++i){
            vector<int> tmp;
            tmp.push_back(1);
            for(int j = 1; j < ans[i-1].size(); ++j){
                tmp.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            tmp.push_back(1);
            ans.push_back(tmp);
        }
        return ans;
    }
};