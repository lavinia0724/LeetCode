# 2024/09/03
class Solution(object):
    def getLucky(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        ans = ""
        for letter in s:
            ans += str(ord(letter) - ord('a') + 1)
        
        while k > 0:
            tmp = 0
            for letter in ans:
                tmp += int(letter)
            ans = str(tmp)
            k -= 1

        return int(ans)