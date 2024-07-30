// 2024/07/30
class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0, bLeft = 0;
        for(int i = 0; i < s.size(); ++i){
            if(bLeft != 0 && s[i] == 'a') {
                ans++;
                bLeft--;
            }
            if(s[i] == 'b') bLeft++;
        }
        return ans;
    }
};