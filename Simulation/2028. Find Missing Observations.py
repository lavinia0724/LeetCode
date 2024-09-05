# 2024/09/05
class Solution(object):
    def missingRolls(self, rolls, mean, n):
        """
        :type rolls: List[int]
        :type mean: int
        :type n: int
        :rtype: List[int]
        """
        totalSum = mean * (len(rolls) + n) 
        outputSum = totalSum - sum(rolls)

        if outputSum > 6 * n or outputSum < n: # 無法填
            return []

        ans = [(outputSum / n) for i in range(n)] # 每格都放 outputSum / n
        
        outputModFix = outputSum % n # 餘數多少代表有多少格又多 + 1
        for i in  range(outputModFix):
            ans[i] += 1

        return ans

"""
ex: rolls = [1,5,6], mean = 3, n = 4
totalSum = 3 * 7 = 21
outputSum = 21 - (1 + 5 + 6) = 9

outputSum / n = 9 / 4 = 2 
ans = [2, 2, 2, 2] 

outputModFix = outputSum % n = 9 % 4 = 1
ans = [3, 2, 2, 2]
"""