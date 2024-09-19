# 2024/09/16
class Solution(object):
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        timeList = []
        for time in timePoints:
            hour = int(time[0:2])
            minute = int(time[3:])

            minute += hour * 60
            timeList.append(minute)

        timeList.sort()
        ans = 24 * 60 + 1
        for i in range(1, len(timeList)):
            ans = min(ans, timeList[i] - timeList[i - 1])

        ans = min(ans, 24 * 60 - timeList[-1] + timeList[0])
        
        return ans

        