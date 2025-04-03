// 2025/04/03
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            vector<int> maxileft(nums.size()), maxiright(nums.size());
            for(int i = 1; i < nums.size(); ++i){
                maxileft[i] = max(maxileft[i-1], nums[i-1]);
                maxiright[nums.size()-i-1] = max(maxiright[nums.size()-i], nums[nums.size()-i]);
            }
    
            long long int ans = 0;
            for(int j = 1; j < nums.size() - 1; ++j){
                ans = max(ans, (long long int)(maxileft[j] - nums[j]) * (long long int)maxiright[j]);
            }
            return ans;
        }
    };