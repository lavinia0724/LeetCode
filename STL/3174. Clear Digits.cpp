// 2025/02/10
class Solution {
    public:
        string clearDigits(string s) {
            stack<char> stk;
            for(auto item: s){
                if(!isdigit(item)) stk.push(item);
                else {
                    if(!stk.empty()) stk.pop();
                }
            }
    
            string ans = "";
            while(!stk.empty()){
                ans = stk.top() + ans;
                stk.pop();
            }
            return ans;
        }
    };