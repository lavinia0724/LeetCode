# 2026/01/01

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        cnt = ""
        for num in digits:
            cnt += str(num)
        
        cnt = str(int(cnt) + 1)

        ans = []
        for num in cnt:
            ans.append(int(num))
        
        return ans