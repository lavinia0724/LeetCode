# 2024/05/13
import numpy as np

class Solution(object):
    def matrixScore(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        grid = np.array(grid)

        # step1: 所有 row 的第一格必都要為 1，這樣加總才會最大
        for i in range(m):
            if grid[i][0] == 0:
                grid[i] = np.where(grid[i] == 0, 1, 0)

        # step2: 所有 column 依序比較，如果 0 的數量較多就 toggle
        for j in range(n):
            tmpsum = 0
            # 如果該 column 加總比 column/2 數量小，代表 0 比較多
            for i in range(m):
                tmpsum += grid[i][j]
                
            if tmpsum <= (m/2):
                for i in range(m):
                    grid[i][j] = np.where(grid[i][j] == 0, 1, 0)

        # step3: 把每行 row (nparray) 轉換成字串，再轉換成二進位數字，並加總
        ans = 0
        for i in range(m):
            binarystr = ''.join(str(bit) for bit in grid[i])
            ans += int(binarystr, 2)

        return ans


        