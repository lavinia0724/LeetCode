// 2024/09/12
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        for(string wordstr: words){
            for(int i = 0; i < wordstr.size(); ++i){
                if(allowed.find(wordstr[i]) == string::npos) break;
                if(i == wordstr.size() - 1) ans++;
            }
        }
        return ans;
    }
};