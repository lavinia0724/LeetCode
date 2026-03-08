// 2026/03/08
class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        
        int mid = 1 << (n - 1);
        if (k == mid) return '1';
        
        if (k < mid) return findKthBit(n - 1, k);
        char res = findKthBit(n - 1, (1 << n) - k);

        return ((res == '0') ? '1' : '0');
    }
};

/*
對稱規律:

index: 1 2 3 4 5 6 7
S3:    0 1 1 1 0 0 1
對稱位置：
1 ↔ 7
2 ↔ 6
3 ↔ 5

***
字串長度:
len = 2^n - 1
對稱位置：
mirror = len - k + 1 = (2^n - 1) - k + 1 = 2^n - k = (1 << n) - k

然後因為右半邊是：reverse(invert(S(n-1)))
所以要找 invert( S(n-1)[mirror] ) 也就是 findKthBit(n-1, mirror)
*/