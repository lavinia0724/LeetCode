# 2024/06/15
# Solution Top 1 的解法，牛逼！
class Solution(object):
    def findMaximizedCapital(self, k, w, profits, capital):
        """
        :type k: int
        :type w: int
        :type profits: List[int]
        :type capital: List[int]
        :rtype: int
        """
        # 可以一口氣放兩個組，使用 capital 來排序
        projects = [(capital[i], profits[i]) for i in range(len(profits))]
        projects.sort()

        maxHeap = []
        i = 0
        for _ in range(k):
            while(i < len(projects) and projects[i][0] <= w):
                    # 因為 heapq 由小到大排序，所以 push -projects[i][1]，這樣最大的反而最小，等等 w 再用 - 的讓他變回正數
                    heapq.heappush(maxHeap, -projects[i][1])
                    i += 1
            # if not <list name> 可以確認 list 是否 empty
            if not maxHeap:
                break
            
            w -= heapq.heappop(maxHeap)

        return w
