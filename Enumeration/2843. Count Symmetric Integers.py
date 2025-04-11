# 2025/04/11
class Solution(object):
    def countSymmetricIntegers(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: int
        """
        ans = 0
        for i in range(low, high+1):
            num = str(i)
            if len(num) % 2 != 0:
                continue

            halfLen = len(num) // 2

            first = sum(ord(char) for char in num[:halfLen])
            last  = sum(ord(char) for char in num[halfLen:])
            if first == last:
                ans += 1
        
        return ans