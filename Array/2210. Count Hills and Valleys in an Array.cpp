// 2025/07/27
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0, prev = nums[0];
        for(int i = 1; i < nums.size() - 1; ++i){
            if(prev == nums[i]) continue;
            if(prev < nums[i]){
                for(int j = i+1; j < nums.size(); ++j){
                    if(nums[j] == nums[i]) continue;
                    else if(nums[j] < nums[i]){
                        ans += 1;
                        i = j - 1;
                    }
                    break;
                }
            }
            else if(prev > nums[i]){
                for(int j = i+1; j < nums.size(); ++j){
                    if(nums[j] == nums[i]) continue;
                    else if(nums[j] > nums[i]){
                        ans += 1;
                        i = j - 1;
                    }
                    break;
                }                
            }
            prev = nums[i];
        }
        return ans;
    }
};