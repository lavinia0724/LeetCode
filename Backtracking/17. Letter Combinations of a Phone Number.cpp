// 2026/05/08
class Solution {
public:
    vector<string> mp = {"", "",  "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtracking(string now, int idx, string digits, vector<string>& ans){
        if(idx == digits.size()){
            ans.push_back(now);
            return;
        }

        int digit = digits[idx] - '0';
        for(int i = 0; i < mp[digit].size(); ++i){
            backtracking(now + mp[digit][i], idx + 1, digits, ans);
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        backtracking("", 0, digits, ans);
        return ans;
    }
};