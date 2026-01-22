// 2026/01/22
class Solution {
public:
    bool isNonDecreasing(const vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;
        while (!isNonDecreasing(nums)) {
            int n = nums.size();
            int minSum = INT_MAX;
            int idx = 0;

            // 找最小相鄰 pair（tie 取最左）
            for (int i = 0; i < n - 1; i++) {
                int s = nums[i] + nums[i + 1];
                if (s < minSum) {
                    minSum = s;
                    idx = i;
                }
            }

            // 合併 nums[idx] 和 nums[idx + 1]
            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);

            operations++;
        }
        return operations;
    }
};