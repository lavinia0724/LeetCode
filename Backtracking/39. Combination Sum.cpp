// 2026/05/08
class Solution {
public:
    void backtracking(vector<int>& now, int idx, int total, vector<int>& candidates, int target, vector<vector<int>>& ans){
        if(total == target){
            ans.push_back(now);
            return;
        }
        
        if(total > target) return;

        for(int i = idx; i < candidates.size(); ++i){
            now.push_back(candidates[i]);
            backtracking(now, i, total + candidates[i], candidates, target, ans);
            now.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> now;
        backtracking(now, 0, 0, candidates, target, ans);
        return ans;
    }
};