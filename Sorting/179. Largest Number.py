# 2024/09/18
class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        numStr = [str(num) for num in nums] # 把 nums 中每個元素轉成 string
        
        numStr.sort(key = lambda x: x * 10, reverse = True) # ex: 9 -> 9999999999, 34 -> 3434343434, reverse = True 是由大到小排序
        
        if numStr[0] == "0": # 最大值就已經是 0 的話
            return "0"

        return "".join(numStr)