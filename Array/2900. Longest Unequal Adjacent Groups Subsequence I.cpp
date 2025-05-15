// 2025/05/15
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int check = 0;
        vector<string> ans1, ans2;
        for(int i = 0; i < words.size(); ++i){
            if(groups[i] == check){ // 從 0 開始，找下一個 1，下下一個 0，依此類推
                ans1.emplace_back(words[i]);
                check = (check + 1) % 2;
            }
        }

    　　check = 1;
        for(int i = 0; i < words.size(); ++i){
            if(groups[i] == check){ // 從 1 開始，找下一個 0，下下一個 1，依此類推
                ans2.emplace_back(words[i]);
                check = (check + 1) % 2;
            }
        }
        
        if(ans1.size() > ans2.size()) return ans1;
        else return ans2;
    }
};