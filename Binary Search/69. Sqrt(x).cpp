// 2026/05/04
class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;

        int ans = 0;
        int left = 0, right = x / 2;
        while(left <= right){
            long long int mid = (left + right) >> 1;
            if(mid * mid <= x){
                ans = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return ans;
    }
};  