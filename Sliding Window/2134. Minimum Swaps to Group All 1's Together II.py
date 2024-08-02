# 2024/08/02
class Solution(object):
    def minSwaps(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 計算整個序列共有多少個 1
        oneNum = 0 
        for num in nums:
            if num == 1:
                oneNum += 1

        if oneNum == 0 or oneNum == len(nums):
            return 0

        # 利用 sliding window 去對每 oneNum 個之中有多少個不是 1 (zeroMiniCnt)
        # zeroMiniCnt 就是最少要 swap 的次數
        # 因為要循環，指標使用 (i + oneNums) % len(nums) 就可以回到頭

        # 先把 slide window 區域數出來
        zeroMiniCnt = 0
        for i in range(oneNum):
            if nums[i] != 1:
                zeroMiniCnt += 1

        tmpZeroNum = zeroMiniCnt
        for i in range(1, len(nums)):
            if nums[i-1] != 1:
                tmpZeroNum -= 1
            if nums[(i + oneNum - 1) % len(nums)] != 1:
                tmpZeroNum += 1
            zeroMiniCnt = min(zeroMiniCnt, tmpZeroNum)

        return zeroMiniCnt
