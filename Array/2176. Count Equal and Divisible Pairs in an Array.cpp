// 2025/04/17
class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            int cnt = 0;
            unordered_map<int, vector<int>> mp;
            for(int i = 0; i < nums.size(); ++i){
                if(mp.count(nums[i]) != 0){
                    for(auto idx: mp[nums[i]]) if(idx * i % k == 0) cnt++;
                }
                mp[nums[i]].emplace_back(i);
            }
            return cnt;
        }
    };