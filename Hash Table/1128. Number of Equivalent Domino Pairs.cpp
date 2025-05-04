// 2025/05/04
class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            unordered_map<string, int> mp;
            for(auto nowpair: dominoes){
                string nowstr = to_string(min(nowpair[0], nowpair[1])) + to_string(max(nowpair[0], nowpair[1]));
                mp[nowstr]++;
            }
            
            int ans = 0;
            for(auto item: mp){
                if(item.second > 1) ans += (item.second * (item.second - 1)) / 2; // Cn 取 2
            }
            return ans;
        }
    };