// 2024/04/29
class Solution {
    public:
        long long numberOfSubarrays(vector<int>& nums) {
            long long ans = 0;
            vector<vector<int>> stk;
            for(int i = 0; i < nums.size(); ++i){
                while(!stk.empty() && stk.back()[0] < nums[i]) stk.pop_back();
    
                if(!stk.empty() && stk.back()[0] == nums[i]){
                    ans += stk.back()[1] + 1; // 包含自己
                    stk.back()[1] += 1;
                }
                else{
                    stk.push_back({nums[i], 1});
                    ans += 1;
                }
            }
    
            return ans;
        }
    };