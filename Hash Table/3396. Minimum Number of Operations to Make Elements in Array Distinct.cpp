// 2025/04/09
class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int cnt = 0;
            bool flag = false;
            for(int i = 0; i < nums.size(); i += 3){
                unordered_map<int, int> mp;
                for(int j = i; j < nums.size(); ++j){
                    if(mp.count(nums[j])) break;
                    mp[nums[j]]++;
                    if(j == nums.size() - 1) flag = true;
                }
                if(flag) break; 
                cnt++;
            }
            return cnt;
        }
    };