/* 2024/04/25
解題思路:
acfb, k = 2
從左至右，依序計算從取出之字母的 +k 或 -k 個字母的 dpLen[] 最大者，然後 +1(加上自己)
dpLen 代表的是，從字串由左至右，已出現的字母，+- k 範圍內的最長 LIS

1 -> a
取 dpLen a, b, c 之中最大者 +1
a c f b
1 0 0 0

2 -> c
取 dpLen a, b, c, d, e 之中最大者 +1，此例取 dpLen[a] = 1 +1
a c f b
1 2 0 0

3 -> f
取 dpLen d, e, f, g, h 之中最大者 +1
a c f b
1 2 1 0

4 -> b
取 dpLen a, b, c, d 之中最大者 +1，此例取 dpLen[c] = 2 +1
a c f b
1 2 1 3

maxi = 3
*/

class Solution {
public:
    int longestIdealString(string s, int k) {
        int dpLen[150];
        memset(dpLen, 0, sizeof(dpLen));

        int maxi = -1;
        for(int i = 0; i < s.size(); ++i){
            int idx = s[i] - 'a';
            for(int j = idx - k; j <= idx + k; ++j){
                if(j < 0 || j > 26) continue;
                dpLen[idx] = max(dpLen[idx], dpLen[j]);
            }
            // 有可能遇到 "aa" 的狀況，因此要在全部其他可能做完後才 +1
            // 否則會影響與其他 dpLen[j] 的大小比較
            dpLen[idx]++; 
            maxi = max(maxi, dpLen[idx]);
        }
        return maxi;
    }
};