// 2026/05/03
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(auto str: strs){
            int zeronum = 0, onenum = 0;
            for(auto s: str){
                if(s == '0') zeronum++;
                else onenum++;
            }

            for(int i = m; i >= zeronum; --i){
                for(int j = n; j >= onenum; --j){
                    dp[i][j] = max(dp[i][j], dp[i-zeronum][j-onenum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};