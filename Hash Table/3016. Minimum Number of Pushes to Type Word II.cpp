// 2024/08/06
class Solution {
public:
    static bool cmp(pair<char,int> a, pair<char, int> b) {
        return a.second > b.second; // 大到小
    }
    
    int minimumPushes(string word) {
        map<char, int> mp;
        for(int i = 0; i < word.size(); ++i){
            mp[word[i]]++;
        }

        vector<pair<char,int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), cmp);

        int cnt = 0, ans = 0;
        for(auto it: v){
            ans += (cnt / 8 + 1) * it.second;
            cnt++;
        }
        return ans;
    }
};