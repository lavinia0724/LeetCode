# 2024/07/19
import numpy as np
class Solution(object):
    def luckyNumbers (self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        npMatrix = np.array(matrix)

        # np.min(0) 是一次取所有 column 的最小值, np.min(-1) 是一次取所有 row 的最小值
        # np.max(0) 是一次取所有 column 的最小值, np.max(1)  是一次取所有 row 的最小值
        miniCol = npMatrix.min(-1) 
        maxRow = npMatrix.max(0)

        ans = []
        for i in range(len(miniCol)):
            if miniCol[i] in maxRow:
                ans.append(miniCol[i])

        return ans
        