// 2026/04/16
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;
        vector<int> ans;
        int n = nums.size();

        for(int i = 0; i < n; ++i) mp[nums[i]].push_back(i);
        for(auto query: queries){
            vector<int>& v = mp[nums[query]];

            if(v.size() > 1){
                int idx = lower_bound(v.begin(), v.end(), query) - v.begin();

                int prev = v[(idx - 1 + v.size()) % v.size()];
                int d1 = min(abs(prev - query), n - abs(prev - query));

                int next = v[(idx + 1) % v.size()];
                int d2 = min(abs(next - query), n - abs(next - query));

                ans.push_back(min(d1, d2));
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};