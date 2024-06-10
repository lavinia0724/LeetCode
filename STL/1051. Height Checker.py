# 2024/06/10
class Solution(object):
    def heightChecker(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        expect = [i for i in heights]
        expect.sort()

        ans = 0
        for i in range(len(heights)):
            if heights[i] != expect[i]:
                ans += 1
        
        return ans
        