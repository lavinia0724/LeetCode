// 2025/05/26
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i = 0; i < words.size(); ++i){
            if(words[i].find(x) != string::npos) ans.emplace_back(i);
        }
        return ans;
    }
};