# 2024/06/17
class Solution(object):
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        # Step 1: 尋找在 [2, c^1/2] 區間是否存在任何可以以 (4k + 3) 表示的因數
        i = 2
        while(i * i <= c):
            if c % i == 0:
                # count: 商
                count = 0
                while c % i == 0:
                    # 做質因數分解
                    count += 1
                    c /= i

                # 如果因數 i 可以以 (4k + 3) 表示，但商 count 出現奇數次，回傳 False
                if (i - 3) % 4 == 0 and count & 1 != 0 :
                    return False
            
            i += 1
        
        # Step 2: 當 c 是質因數，檢查他是否可以(4k + 3) 表示
        # 也檢查被質因數分解完的 c 
        if (c - 3) % 4 != 0:
            return True
        else:
            return False

"""
Fermat Theorem:
a^2 + b^ = c^2 (n)
Any positive number n is expressible as a sum of two squares if and only if the prime factorization of n, every prime of the form (4k+3) occurs an even number of times.

Step 1:
尋找在 [2, c^1/2] 區間是否存在任何可以以 (4k + 3) 表示的因數，當該因數存在奇數次，就回傳 False

Step 2:
但如果 c 是質因數，要確認的是他自己是否是以 (4k + 3) 表示，因為質因數不可分解，所以一旦是以 (4k + 3) 表示，即必僅出現一次 (奇數次)，故回傳 False
"""