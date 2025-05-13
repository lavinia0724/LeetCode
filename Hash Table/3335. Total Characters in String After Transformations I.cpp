// 2025/05/13
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int mod = 1e9 + 7;
        vector<int> cnt(26);
        for(auto num: s) cnt[num - 'a']++;

        for(int i = 0; i < t; ++i){
            int Znum = cnt[25];
            for(int i = 24; i >= 0; --i) cnt[i+1] = cnt[i];
            cnt[0] = Znum; // z -> ab 的 a
            cnt[1] = (cnt[1] + Znum) % mod; // z -> ab 的 b 要加上原本是 a 的數量
        }

        int ans = 0;
        for(int i = 0; i < 26; ++i){
            ans = (ans + cnt[i]) % mod;
        }
        return ans;
    }
};