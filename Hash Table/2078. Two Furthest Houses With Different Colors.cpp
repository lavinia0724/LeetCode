// 2026/04/20
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size(), maxi = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i){
            if(mp.find(colors[i]) == mp.end()) mp[colors[i]] = i;
            for(auto it: mp){
                if(it.first != colors[i]) maxi = max(maxi, abs(i - it.second));
            }
        }
        return maxi;
    }
};