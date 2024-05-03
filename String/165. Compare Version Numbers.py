# 2024/05/03
class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        versionsplit1 = version1.split('.')
        versionsplit2 = version2.split('.')
        
        strminlen = min(len(versionsplit1), len(versionsplit2))
        for i in range (strminlen):
            if int(versionsplit1[i]) < int(versionsplit2[i]) :
                return -1
            elif int(versionsplit1[i])  > int(versionsplit2[i]) :
                return 1

        if len(versionsplit2) > len(versionsplit1):
            for i in range (len(versionsplit1), len(versionsplit2)):
                if int(versionsplit2[i]) != 0: 
                    return -1
        elif len(versionsplit1) > len(versionsplit2):
            for i in range (len(versionsplit2), len(versionsplit1)):
                if int(versionsplit1[i]) != 0: 
                    return 1

        return 0