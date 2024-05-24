# 參考 Mohammed Raziullah Ansari 的 solution
class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        def is_palindrome(substr):
            return substr == substr[::-1]

        # **是先 end 到下一位，但計算回文到 end 前一位，所以最後 end 是 len(s) + 1**
        # "aab"
        # -> 
        # for .. :
        # start = 0, "a", end = 1, "a"
        # s[start:end]: "a" is palindrome
        # -> -> 
        # for .. :
        # start = 1, "a", end = 2, "b"
        # s[start:end]: "a" is palindrom
        # -> -> -> 
        # for .. :
        # start = 2, "b", end = 3, ""
        # s[start:end]: "b" is palindrom
        # -> -> -> ->
        # start = 3 == len(s)
        # path = ["a", "a", "b"]
        # result.append(path[:]), return
        # -> -> ->
        # for .. : for 迴圈結束，回到上一層
        # -> ->
        # for .. :
        # start = 1, "a", end = 3, ""
        # s[start:end]: "ab" is not palindrome, for 迴圈結束，回到上一層
        # ->
        # for .. :
        # start = 0, "a", end = 2, "b"
        # s[start:end]: "aa" is palindrom
        # -> -> for .. :

        def dfs(start, path):
            if start == len(s):
                result.append(path[:])
                return 
            # for 迴圈故意跑到 len(s) + 1
            for end in range(start + 1, len(s) + 1):
                # print(s[start:end],  s[end:start:-1])
                if is_palindrome(s[start:end]):
                    dfs(end, path + [s[start:end]])

        result = []
        dfs(0, [])

        return result
        