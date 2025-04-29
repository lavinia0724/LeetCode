// 2025/04/29
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            return atLeastK(nums, k); // 原因可看 3306. 那題
        }
    
        long long atLeastK(vector<int>& nums, int k){
            int maxi = *std::max_element(nums.begin(), nums.end());
    
            long long ans = 0;
            int left = 0, cnt = 0;
            for(int right = 0; right < nums.size(); ++right){
                if(nums[right] == maxi) cnt++;
    
                while(cnt == k){
                    ans += (nums.size() - right);
    
                    if(nums[left] == maxi) cnt--;
                    left++;
                }
            }
            return ans;
        }
    };