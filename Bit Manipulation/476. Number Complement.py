# 2024/08/22
class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        mask = (1 << num.bit_length()) - 1 # 創建全部都是 1 且和 num 二進位 bits 長度等長的 mask
        ans = (~num) & mask # 5 = 0000 0101, ~5 = 1111 1010, mask = 0000 0111
        return ans

        