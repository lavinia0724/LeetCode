// 2025/04/28
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            long long ans = 0, total = 0;
            int left = 0;
            for(int right = 0; right < nums.size(); ++right){
                total += nums[right];
                while(total * (right - left + 1) >= k){
                    total -= nums[left];
                    left++;
                }
                ans += (right - left + 1);
            }
            return ans;
        }
    };