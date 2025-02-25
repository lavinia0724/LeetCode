// 2025/02/18
class Solution {
    public:
        string smallestNumber(string pattern) {
            stack<int> st;
            string ans = "";
    
            for(int i = 0; i <= pattern.size(); ++i){
                st.push(i+1);
    
                if(pattern[i] == 'I' || i == pattern.size()){
                    while(!st.empty()){
                        ans += to_string(st.top());
                        st.pop();
                    }
                }
            }
            return ans;
        }
    };