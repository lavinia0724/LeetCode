// 2026/04/19
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int ans = INT_MAX, n = nums.size();
        unordered_map<int, int> mp;
        for(int i = n - 1; i >= 0; --i){

            string rev_num = to_string(nums[i]);
            reverse(rev_num.begin(), rev_num.end());

            if(mp.find(stoi(rev_num)) != mp.end()) ans = min(ans, abs(i - mp[stoi(rev_num)]));
            mp[nums[i]] = i;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};