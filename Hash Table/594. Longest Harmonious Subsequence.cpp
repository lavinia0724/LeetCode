// 2025/06/30
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> mp;
        for(auto num: nums) mp[num]++;

        int maxi = 0;
        for(auto it = mp.begin(); it != mp.end(); ++it){
            if(mp.find(it->first-1) == mp.end()) continue;
            maxi = max(maxi, abs(it->second + mp[it->first-1]));
        }
        return maxi;
    }
};