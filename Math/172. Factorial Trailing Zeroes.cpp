// 2026/05/04
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n > 0){ // 因為有些數字會提供不只一個 5，所以不能直接 ans += n / 5 就好，while 是必要的
            ans += n / 5;  // 如果只算 n / 5，會漏掉 25, 50, 75, 100... 裡面多出來的那個 5
            n /= 5; // 這邊 /= 5 相當於 去處理 5、25 ...
        }
        return ans;
    }
};