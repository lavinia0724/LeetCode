// 2025/02/28
class Solution {
    public:
        string shortestCommonSupersequence(string str1, string str2) {
            int str1Len = str1.size();
            int str2Len = str2.size();
    
            vector<vector<int>> dp(str1Len + 1, vector<int>(str2Len + 1, 0));
    
            for(int row = 1; row <= str1Len; ++row){
                for(int col = 1; col <= str2Len; ++col){
                    if(str1[row - 1] == str2[col - 1]){
                        dp[row][col] = dp[row - 1][col - 1] + 1;
                    }
                    else{
                        dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]);
                    }
                }
            }
    
            string outputStr = "";
            int row = str1Len, col = str2Len;
    
            while(row > 0 && col > 0){
                if(str1[row - 1] == str2[col - 1]){
                    outputStr += str1[row - 1];
                    row--;
                    col--;
                }
                else if(dp[row - 1][col] > dp[row][col - 1]){
                    outputStr += str1[row - 1]; // str1 的這個字元要接上 outputStr
                    row--;
                }
                else {
                    outputStr += str2[col - 1]; // str2 的這個字元要接上 outputStr
                    col--;
                }
            }
    
            while(row > 0){
                outputStr += str1[row - 1]; 
                row--;
            }
            while(col > 0){
                outputStr += str2[col - 1]; 
                col--;
            }
    
            reverse(outputStr.begin(), outputStr.end());
            return outputStr;
        }
    };