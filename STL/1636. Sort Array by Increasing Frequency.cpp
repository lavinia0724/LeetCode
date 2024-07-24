// 2024/07/24
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); ++i) mp[nums[i]]++;

        vector<pair<int, int>> v;
        for(auto& it: mp) v.emplace_back(it);

        sort(v.begin(), v.end(), [](auto& a, auto& b) {return (a.second != b.second) ? (a.second < b.second) : (a.first > b.first);});

        vector<int> ans;
        for(auto& it: v) 
            for(int i = 0; i < it.second; ++i)
                ans.emplace_back(it.first);

        return ans;
    }
};