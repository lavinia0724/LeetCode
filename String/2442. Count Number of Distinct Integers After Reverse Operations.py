# 2024/05/02
class Solution(object):
    def countDistinctIntegers(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = []
        
        for i in range(len(nums)):
            ans.append(nums[i])
        
        for i in range(len(nums)):
            ans.append(int(str(nums[i])[::-1]))

        return len(set(ans))
        