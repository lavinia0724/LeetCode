# 2024/05/20
class Solution(object):
    def subsetXORSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # bit manipulation (by Editorial)
        # 可以觀察到，按照每個 subset 的加總，也就是把所有數字的 bit 做 or 後的結果，然後在右側補上 N-1 個 0
        # 1:  0 0 1
        # 5:  1 0 1
        # 6:  1 1 0
        # or: 1 1 1
        # ans 28: 1 1 1 0 0
        ans = 0
        N = len(nums)
        for i in range(N):
            ans = ans | nums[i]
        
        # decimal to binary
        bin(ans).replace("0b", "")

        # 右邊補 N-1 個 0，也就是往左移 N-1 個 bit
        ans = ans << N-1

        return ans
        