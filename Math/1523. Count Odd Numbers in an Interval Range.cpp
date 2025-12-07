// 2025/12/07
class Solution {
public:
    int countOdds(int low, int high) {
        int ans = (high - low) / 2;
        if((high & 1) || (low & 1)) ans++;
        return ans;
    }
};