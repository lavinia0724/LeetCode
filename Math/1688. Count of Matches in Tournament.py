# 2024/05/02
class Solution(object):
    def numberOfMatches(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = 0
        while n > 1:
            if n & 1 == 0: # even
                ans += n/2
                n /= 2
            else:          # odd
                ans += (n-1)/2
                n = (n-1)/2 +1
            
        return ans