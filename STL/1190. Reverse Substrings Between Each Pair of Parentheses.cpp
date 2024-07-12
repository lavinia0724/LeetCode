// 2024/07/11
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        string ans = "";
        bool checker = false;
        
        for(int i = 0; i < s.size(); ++i){
            string temp(1, s[i]);
            if(s[i] == ')'){
                string tmp = "";
                while(stk.top() != "("){
                    tmp += stk.top();
                    stk.pop();
                }
                stk.pop();

                reverse(tmp.begin(), tmp.end());
                stk.push(tmp);
            }
            else stk.push(temp);
        }

        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};