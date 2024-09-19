# 2024/09/17
class Solution(object):
    def uncommonFromSentences(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: List[str]
        """
        s1 = s1.split(' ')
        s2 = s2.split(' ')

        ans = {} # python dict (= c++ map)
        for string in s1:
            ans[string] = ans.get(string, 0) + 1

        for string in s2:
            ans[string] = ans.get(string, 0) + 1

        return [word for word in ans if ans[word] == 1]

        