// 2025/04/27
class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int cnt = 0;
            for(int i = 0; i < nums.size() - 2; ++i){
                if((nums[i] + nums[i+2]) * 2 == nums[i+1]) cnt++;
            }
            return cnt;
        }
    };