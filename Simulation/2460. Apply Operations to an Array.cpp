// 2025/03/01
class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int backZeroCnt = 0;
            vector<int> ans;
            for(int i = 0; i < nums.size(); ++i){
                if(nums[i] == 0) backZeroCnt++;
                else if(i == nums.size() - 1) ans.emplace_back(nums[i]);
                else if(nums[i] == nums[i+1]){
                    ans.emplace_back(nums[i] * 2);
                    backZeroCnt++;
                    i++;
                }
                else ans.emplace_back(nums[i]);
            }
            while(backZeroCnt--) ans.emplace_back(0);
            return ans;
        }
    };