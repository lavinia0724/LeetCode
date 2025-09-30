// 2025/09/30
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        vector<int> firstLenSum(nums.size(), 0), secondLenSum(nums.size(), 0);
        int firstLenSlidingWindow = 0, secondLenSlidingWindow = 0;
        for(int left = 0; left < nums.size(); ++left){
            firstLenSlidingWindow += nums[left];
            if(left >= firstLen) firstLenSlidingWindow -= nums[left - firstLen];
            firstLenSum[left] = firstLenSlidingWindow;
        }
        for(int right = nums.size() - 1; right >= 0; --right){
            secondLenSlidingWindow += nums[right];
            if(right + secondLen < nums.size()) secondLenSlidingWindow -= nums[right + secondLen];
            secondLenSum[right] = secondLenSlidingWindow;
        }

        int maxi = 0;
        for(int left = firstLen - 1; left < nums.size(); ++left){
            for(int right = left + 1; right < nums.size() - secondLen + 1; ++right){
                maxi = max(maxi, firstLenSum[left] + secondLenSum[right]);
            }
        }
        for(int left = 0; left < nums.size() - secondLen + 1; ++left){
            for(int right = left + secondLen + firstLen; right < nums.size(); ++right){
                maxi = max(maxi, secondLenSum[left] + firstLenSum[right]);
            }
        }
        return maxi;
    }
};