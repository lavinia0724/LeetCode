// 2026/05/08
class Solution {
public:
    void backtracking(vector<int>& now, int idx, int n, int k, vector<vector<int>>& ans){
        if(now.size() == k){
            ans.push_back(now);
            return;
        }

        for(int i = idx; i <= n; ++i){
            now.push_back(i);
            backtracking(now, i + 1, n, k, ans);
            now.pop_back();
        }
        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> now;
        backtracking(now, 1, n, k, ans);
        return ans;
    }
};