// 2025/07/21
class Solution {
public:
    string makeFancyString(string s) {
        int cnt = 0;
        for(int i = 1; i < s.size(); ++i){
            if(s[i-1] == s[i]) cnt++;
            if(s[i-1] != s[i] || i == s.size()-1) {
                if(cnt >= 2) {
                    s.erase(s.begin() + i - cnt, s.begin() + i - 1);
                    i -= cnt - 1;
                }
                cnt = 0;
            }
        }
        return s;
    }
};