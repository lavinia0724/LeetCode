// 2024/06/05
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int minAlphabet[26];
        memset(minAlphabet, 0x3f3f3f3f, sizeof(minAlphabet));

        for(int i = 0; i < words.size(); ++i){
            int alphabet[26] = {0};
            for(int j = 0; j < words[i].size(); ++j){
                alphabet[words[i][j] - 'a']++;
            }
            for(int j = 0; j < 26; ++j){
                minAlphabet[j] = min(minAlphabet[j], alphabet[j]);
            }
        }

        vector<string> ans;
        for(int i = 0; i < 26; ++i){
            while(minAlphabet[i] != 0x3f3f3f3f && minAlphabet[i] > 0){
                string tmp(1, char('a' + i));
                ans.push_back(tmp);
                minAlphabet[i]--;
            }
        }

        return ans;
    }
};