// 2026/05/07
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixMax(n), suffixMin(n);

        // 如果在某個位置 i 可以切開，代表左半邊所有值 <= 右半邊所有值，兩邊就不會互相連通
        // 這題要找的是這個 idx 所在的那個區域裡面誰是最大值

        prefixMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }

        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }

        vector<int> ans(n);
        int start = 0;
        int curMax = nums[0];

        for (int i = 0; i < n; ++i) {
            curMax = max(curMax, nums[i]);

            // 可以在 i 後面切開
            if (i == n - 1 || prefixMax[i] <= suffixMin[i + 1]) {
                for (int j = start; j <= i; ++j) {
                    ans[j] = curMax;
                }

                start = i + 1;
                if (start < n) curMax = nums[start];
            }
        }

        return ans;
    }
};