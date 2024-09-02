# 2024/09/02
class Solution(object):
    def chalkReplacer(self, chalk, k):
        """
        :type chalk: List[int]
        :type k: int
        :rtype: int
        """
        total = sum(chalk, 0)

        if k % total == 0:
            return 0
        
        k %= total
        for i in range(len(chalk)):
            if k - chalk[i] < 0:
                return i
            k -= chalk[i]

        return 0