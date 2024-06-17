# 2024/06/17
class Solution(object):
    def minPatches(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: int
        """
        ans = 0

        # farPtr: 目前可以加總到的最遠距離是到 num[i] + sumPtr
        # 確認 farPtr 他自己可以加總到的最遠距離 farPtr + (farPtr - 1) 再 + 1 是否已存在於 nums
        farPtr = 1 + 0
        i = 0
        while farPtr <= n:
            # 節至某格 nums[i] 為止，這個 num 小於 farPtr，代表它已經可以被加總出來，所以 farPtr 再加上這個 num，讓加總到的最遠距離可以變得更遠
            if i < len(nums) and nums[i] <= farPtr:
                farPtr += nums[i]
                i += 1
            # 反之，如果 nums[i] 比 farPtr，代表目前的 farPtr 還沒到達可以組出他的距離，則更新 farPtr + (farPtr - 1) 再 + 1 
            else:
                farPtr += farPtr
                ans += 1

        return ans

"""
Case 2: nums = [1, 5, 10], n = 20

* farPtr = 1, i = 0
nums[0] = 1 <= farPtr 
farPtr += nums[0]: farPtr = 1 + 1 = 2
i += 1
目前總共可以用來組合的數字有 [1]
現在可以證明到 farPtr = 2 - 1 的 1 為止，存在 [1] 可以組合出 1，現在把 farPtr 更新到未知是否可以的 2

* farPtr = 2, i = 1
nums[1] = 5 > farPtr 
farPtr += farPTr: farPtr = 2 + 2 = 4
ans += 1 (因為 patches 2)
因為 5 無法被組出來，所以要加入 "2"
目前總共可以用來組合的數字有 [1, 2]

* farPtr = 4, i = 1
nums[1] = 5 > farPtr 
farPtr += farPTr: farPtr = 4 + 4 = 8
ans += 1 (因為 patches 4)
因為 5 還是無法被組出來，所以要加入 "4"
目前總共可以用來組合的數字有 [1, 2, 4]

* farPtr = 8, i = 1
nums[1] = 5 <= farPtr 
farPtr += nums[1]: farPtr = 8 + 5 = 13
i += 1
目前總共可以用來組合的數字有 [1, 2, 4, 5]
現在可以證明到 farPtr = 13 - 1 的 12 為止，存在 [1], [2], [1, 2], [4], [5], [1, 2, 3], [1, 2, 4], [1, 2, 5], [4, 5], [1, 4, 5], [2, 4, 5], [1, 2, 4, 5] 可以組合出 1 ~ 12，現在把 farPtr 更新到未知是否可以的 13

* farPtr = 13, i = 2
nums[2] = 10 <= farPtr 
farPtr += nums[2]: farPtr = 13 + 10 = 23
i += 1
目前總共可以用來組合的數字有 [1, 2, 4, 5, 10]
現在可以證明到 farPtr = 23 - 1 的 22 為止，存在 [1], [2], [1, 2], [4], [5], [1, 2, 3], [1, 2, 4], [1, 2, 5], [4, 5], [10], [1, 10], [2, 10], [1, 2, 10], [4, 10], [5, 10], [1, 5, 10], [2, 5, 10], [1, 2, 5, 10], [4, 5, 10], [1, 4, 5, 10], [2, 4, 5, 10], [1, 4, 5, 10] 可以組合出 1 ~ 22，現在把 farPtr 更新到未知是否可以的 23
而其中，也可以發現我們現已可以解出 n (n = 20)

* farPtr = 23 > n (n = 20)
break
"""