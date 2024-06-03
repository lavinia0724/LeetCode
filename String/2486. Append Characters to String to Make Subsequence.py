# 2024/06/03
class Solution(object):
    def appendCharacters(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        ptr = 0
        for i in range(len(s)):
            if s[i] == t[ptr]:
                ptr += 1
                if ptr == len(t):
                    break
        
        return len(t) - ptr
        