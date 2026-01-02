// 2026/01/02
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto num: nums) mp[num]++;
        for(auto item: mp){
            if(item.second == nums.size() / 2) return item.first;
        }
        return -1;
    }
};