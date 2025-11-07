// 2025/11/07
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans(nums.size() - k + 1, 0);
        for(int i = 0; i <= nums.size() - k; ++i){
            unordered_map<int, int> mp;
            for(int j = 0; j < k; ++j) mp[nums[i + j]]++;
            
            vector<pair<int, int>> v(mp.begin(), mp.end());
            sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
                if (a.second == b.second) return a.first > b.first; // 數值大的優先
                return a.second > b.second; // 次數多的優先
            });
            for(int j = 0; j < x && j < v.size(); ++j) ans[i] += v[j].first * v[j].second;
        }
        return ans;
    }
};