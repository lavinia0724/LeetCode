// 2025/04/01
class Solution {
    public:
        long long int dpDFS(int idx, vector<vector<int>>& questions, vector<long long int>& dp){
            if(idx >= questions.size()) return 0;
            if(dp[idx] != -1) return dp[idx]; // 已經有更新過就直接 return
    
            long long int solve = questions[idx][0] + dpDFS(idx + questions[idx][1] + 1, questions, dp); // 如果我選擇解這題，可以獲得多少 point
            long long int skip = dpDFS(idx + 1, questions, dp); // 如果我選擇跳過這題，可以獲得多少 point
    
            return dp[idx] = max(solve, skip);
        }
    
        long long mostPoints(vector<vector<int>>& questions) {
            vector<long long int> dp(questions.size(), -1);
            return dpDFS(0, questions, dp);
        }
    };