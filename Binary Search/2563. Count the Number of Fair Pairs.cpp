// 2025/04/30
class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            sort(nums.begin(), nums.end());
            return lower_bound(nums, upper + 1) - lower_bound(nums, lower);
        }
    
        long long lower_bound(vector<int>& nums, int val){
            int left = 0, right = nums.size() - 1;
            long long cnt = 0;
            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum < val){
                    cnt += (right - left); // 這個範圍內的所有 num 相加都可以 < val
                    left++;
                }
                else right--;
            }
            return cnt;
        }
    };