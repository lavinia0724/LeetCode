"""
2024/05/10 
python - heappq
建立一個 heap 可以使用 list 初始化為 []

heapq.heappush(heap, item)
heapq.heappop(heap)

heapq.heapify(x) 在線性時間內將 list x 轉為 heap
還有很多用法
"""

class Solution(object):
    def kthSmallestPrimeFraction(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """

        minheap = []
        for i in range(len(arr)):
            for j in range(i+1, len(arr)):
                # 總共推了三個 item 進 minheap: arr[i]/arr[j]、arr[i], arr[j]
                heappush(minheap, (float(arr[i])/float(arr[j]), arr[i], arr[j]))
        
        for i in range(k):
            ans = heappop(minheap)
            
        return ans[1:]