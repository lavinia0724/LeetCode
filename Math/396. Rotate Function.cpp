// 2026/05/01
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long int curr = 0, totalSum = 0;
        for(int i = 0; i < n; ++i){
            curr += i * nums[i];
            totalSum += nums[i];
        }

        int ans = INT_MIN;
        for(int i = 0; i < n; ++i){
            curr = curr + totalSum - 1LL * n * nums[n - i - 1];
            ans = max(ans, (int)curr);
        }
        return ans;
    }
};