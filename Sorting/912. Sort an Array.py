# 2024/07/25
class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        mini = min(nums)
        maxi = max(nums)
        # 開一個長度為 maxi - mini +1 的 list 且初始化值都是 0
        numCnt = [0] * (maxi - mini + 1)
        
        # numCnt[num - mini] 是所有值的數量，由小到大，計算個數
        # O(n)
        for num in nums:
            numCnt[num - mini] += 1

        idx = 0
        for i in range(len(numCnt)):
            while numCnt[i] > 0:
                nums[idx] = i + mini
                numCnt[i] -= 1
                idx += 1
        
        return nums
        