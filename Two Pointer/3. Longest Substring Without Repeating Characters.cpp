// 2026/05/08
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0 || n == 1) return n;

        int ans = 0;
        int left = 0, right = 0;
        unordered_set<char> st;

        while(right < n){
            if(st.find(s[right]) == st.end()){
                st.insert(s[right]);
                right++;
            }
            else if(st.find(s[right]) != st.end()){
                st.erase(s[left]);
                left++;
            }

            ans = max(ans, (int)st.size());
        }
        return ans;
    }
};