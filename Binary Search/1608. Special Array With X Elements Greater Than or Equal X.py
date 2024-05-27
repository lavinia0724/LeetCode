# 2024/05/27
class Solution(object):
    def specialArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def binary_search(lef, rig, ans, x):
            mid = (lef + rig) >> 1

            print(lef, rig, mid, nums[mid], ans)
            if rig < lef:
                return ans
            if rig == lef or ans == mid:
                return rig

            if nums[mid] == x and nums[max(0, mid-1)] != x and nums[min(len(nums)-1, mid+1)] != x:
                return mid

            if nums[mid] >= x:
                return binary_search(lef, mid, mid, x)
            if nums[mid] < x:
                return binary_search(mid, rig, mid, x)


        nums.sort()
        for x in range(len(nums)+1):
            idx = binary_search(0, len(nums), -1, x)
            if len(nums) - idx == x:
                return x
        
        return -1
        