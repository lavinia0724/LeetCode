// 2024/10/10
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int ans = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ')'){
                if(!stk.empty()) stk.pop();
                else ans ++;
            }
            else stk.push(s[i]);
        }
        return stk.size() + ans;
    }
};