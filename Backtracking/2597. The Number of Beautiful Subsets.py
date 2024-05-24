# 2024/05/23
class Solution(object):
    def beautifulSubsets(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # backtrack: [2, 4, 6], k = 2
        # -> -> 6
        # cnt = 1 + 1 = 2
        # 也就是 [6] 和 nums[idx] - k not in freqMap，[6, 4]
        # -> 4
        # cnt = 2 + 1 = 3
        # 2 是 [6] 和 [6, 4]，多了的 1 是 [4]
        # 2
        # cnt = 3 + 2 = 5
        # 多了 [2] 和 [2, 6]
        # 所以最後 return ans 要 -1，減掉多算的 [6, 4]
        def dfs(nums, k, freqMap, idx):
            # Base case: Return 1 for a subset of size 1
            if idx == len(nums):
                return 1

            # Count subsets where nums[idx] is not taken
            cnt = dfs(nums, k, freqMap, idx + 1)

            if nums[idx] - k not in freqMap:
                freqMap[nums[idx]] += 1

                cnt += dfs(nums, k, freqMap, idx + 1)
                # Backtrack: mark nums[idx] as not taken
                freqMap[nums[idx]] -= 1

                # Remove nums[idx] from freq_map if its count becomes 0
                if freqMap[nums[idx]] == 0:
                    del freqMap[nums[idx]]
            
            return cnt

        # 帶有預設值的 dictionary ，第一個參數是一個可呼叫的物件，後面接的參數會直接給 dict 當參數使用
        # defaultdict(int, {'a': 10, 'b': 20})
        freqMap = defaultdict(int)

        nums.sort()
        return dfs(nums, k, freqMap, 0) - 1

    



        