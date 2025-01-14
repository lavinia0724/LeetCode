// 2025/01/10
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<vector<int>> word1CharacterCnt(words1.size(), vector<int>(26, 0));
        vector<int> word2CharacterCnt(26, 0);

        for(int i = 0; i < words1.size(); ++i)
            for(int j = 0; j < words1[i].size(); ++j)
                word1CharacterCnt[i][words1[i][j] - 'a']++;
            
        for(int i = 0; i < words2.size(); ++i){
            int tmpCharacterCnt[26] = {0};
            for(int j = 0; j < words2[i].size(); ++j)
                tmpCharacterCnt[words2[i][j] - 'a']++;
            for(int j = 0; j < 26; ++j)
                word2CharacterCnt[j] = max(word2CharacterCnt[j], tmpCharacterCnt[j]);
        }

        bool flag = false;
        vector<string> ans;
        for(int i = 0; i < words1.size(); ++i){
            for(int j = 0; j < 26 && !flag; ++j){
                if(word1CharacterCnt[i][j] < word2CharacterCnt[j]) flag = true;
            }
            if(!flag) ans.push_back(words1[i]);
            flag = false;
        }

        return ans;
    }
};