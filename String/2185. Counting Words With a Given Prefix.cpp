// 2025/01/09
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(auto word: words)
            if(pref == word.substr(0, pref.size())) ans++;
        
        return ans;
    }
};