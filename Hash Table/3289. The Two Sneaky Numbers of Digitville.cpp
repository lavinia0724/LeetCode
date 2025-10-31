// 2025/10/31
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = 0;
        for(auto num: nums){
            mp[num]++;
            maxi = max(maxi, mp[num]);
        }

        vector<int> ans;
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second == maxi) ans.emplace_back(it->first);
        }
        return ans;
    }
};