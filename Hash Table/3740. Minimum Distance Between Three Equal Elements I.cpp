// 2026/04/10
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); ++i){
            if(mp[nums[i]].size() < 2) mp[nums[i]].emplace_back(i);
            else{
                ans = min(ans, abs(i - mp[nums[i]][1]) + abs(mp[nums[i]][1] - mp[nums[i]][0]) + abs(mp[nums[i]][0] - i));
                
                mp[nums[i]][0] = mp[nums[i]][1];
                mp[nums[i]][1] = i;
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};