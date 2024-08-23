# 2024/08/23
import re
class Solution(object):
    def fractionAddition(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        def findgcd(a, b):
            if b == 0:
                return a
            else:
                return findgcd(b, a % b)

        # re.split 中 ([]) 是要切割的字元
        # ? 表示前面的元素出現 0 次或 1 次
        # \d 代表任意一個數字字符（0-9），+ 表示前面的元素出現 1 次或多次；匹配至少一個數字，並且可以匹配多個連續的數字
        # 將 "-1/2+1/2" 切成 [u'', u'-1', u'', None, u'', u'2', u'', u'+1', u'', None, u'', u'2', u'']
        nums = re.split(r'/|([+-]?\d+)', expression) 
        nums = [x for x in nums if x not in ('', None)] # 去掉 '' 和 None

        numeratorAll = 0
        denominatorAll = 1
        for i in range(0, len(nums), 2):
            numerator = int(nums[i])
            denominator = int(nums[i+1])

            numeratorAll = numeratorAll * denominator + numerator * denominatorAll
            denominatorAll = denominatorAll * denominator

        gcd = findgcd(numeratorAll, denominatorAll)

        numeratorAll //= gcd
        denominatorAll //= gcd

        return str(numeratorAll) + "/" + str (denominatorAll)
