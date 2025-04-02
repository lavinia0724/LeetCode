// 2025/04/02
class Solution {
    public:
        int numberOfSubstrings(string s) {
            unordered_map<char, int> mp;
            int ans = 0, left = 0;
            for(int right = 0; right < s.size(); ++right){
                mp[s[right]]++;
    
                while(mp.size() == 3){
                    ans += s.size() - right;
    
                    mp[s[left]]--;
                    if(mp[s[left]] == 0) mp.erase(s[left]);
                    left++;
                }
            }
            return ans;
        }
    };