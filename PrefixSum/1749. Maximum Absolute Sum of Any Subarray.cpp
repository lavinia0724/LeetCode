// 2025/03/05
class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int prefixSum = 0;
            int minPrefixSum = 0;
            int maxPrefixSum = 0;
            for(auto num: nums){
                prefixSum += num;
                minPrefixSum = min(minPrefixSum, prefixSum);
                maxPrefixSum = max(maxPrefixSum, prefixSum);
            }
            return maxPrefixSum - minPrefixSum;
        }
    };