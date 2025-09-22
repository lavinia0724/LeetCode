// 2025/09/22
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxifreq = 0;
        for(auto num: nums) {
            mp[num]++;
            maxifreq = max(maxifreq, mp[num]);
        }

        int ans = 0;
        for(auto it = mp.begin(); it != mp.end(); ++it)
            if(it->second == maxifreq) ans += maxifreq;
        
        return ans;
    }
};