// 2026/03/05
class Solution {
public:
    int minOperations(string s) {
        int cnt1 = 0, cnt0 = 0;
        for(int i = 0; i < s.size(); ++i){
            if((i % 2) != s[i] - '0') cnt1++;
        }
        for(int i = 0; i < s.size(); ++i){
            if((i % 2) != s[i] - '0') cnt0++;
        }
        cnt1 = (s.size() - cnt1);
        return min(cnt1, cnt0);
    }
};