// 2025/10/13
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.emplace_back(words[0]);
        for(int i = 1; i < words.size(); ++i){
            string prev = words[i - 1];
            string curr = words[i];

            sort(prev.begin(), prev.end());
            sort(curr.begin(), curr.end());

            if (prev != curr) {
                ans.emplace_back(words[i]);
            }
        }
        return ans;
    }
};