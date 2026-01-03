// 2026/01/03
class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;

        // 第 1 列有兩種起始可能
        long long dpA = 6; // ABC 類型
        long long dpB = 6; // ABA 類型

        for (int i = 2; i <= n; i++) {
            long long nextdpA = (dpA * 2 + dpB * 2) % MOD;
            long long nextdpB = (dpA * 2 + dpB * 3) % MOD;

            dpA = nextdpA;
            dpB = nextdpB;
        }
        return (dpA + dpB) % MOD;
    }
};

/*
經典狀態 DP 題
三色塗格，相鄰 (上下左右) 不可相同

第 1 列有兩種起始可能:

ABC 類型，三個顏色都不同:
R G Y
Y R G
一列裡合法排列數量: 3 × 2 = 6

ABA 類型，左右同色，中間一定不同:
R G R
Y R Y
一列裡合法排列數量: 3 × 2 = 6



下一列轉移關係一樣都會有兩種:

第 i 列是 ABC:
從前一列 ABC 轉來：2 種
R G Y
下一列可轉 -> Y R G 或 G Y R，一定只有這兩種
從前一列 ABA 轉來：2 種
R G R
下一列可轉 -> Y R G  或 G R Y，一定只有這兩種
所以 dpA[i] = dpA[i-1] * 2 + dpB[i-1] * 2

第 i 列是 ABA
從前一列 ABC 轉來：2 種
R G Y
下一列可轉 -> G Y G 或 G R G，一定只有這兩種
從前一列 ABA 轉來：3 種
R G R
下一列可轉 -> Y R Y 或 G R G 或 GY G，一定只有這三種

所以 dpB[i] = dpA[i-1] * 2 + dpB[i-1] * 3

最後 dpA + dpB
*/