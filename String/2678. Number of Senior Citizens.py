# 2024/08/01
class Solution(object):
    def countSeniors(self, details):
        """
        :type details: List[str]
        :rtype: int
        """
        ages = [age[11:13] for age in details]
        ages = map(int, ages) # 把 ages 內的 str 皆轉成 int

        ans = 0
        for age in ages:
            if age > 60:
                ans += 1
        return ans