// 2026/05/08
class Solution {
public:
    void backtracking(string now, int left, int right, int n, vector<string>& ans){
        if(now.size() == 2 * n){
            ans.push_back(now);
            return;
        }

        if(left < n){
            backtracking(now + "(", left + 1, right, n, ans);
        }

        if(right < left){
            backtracking(now + ")", left, right + 1, n, ans);
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtracking("", 0, 0, n, ans);
        return ans;
    }
};