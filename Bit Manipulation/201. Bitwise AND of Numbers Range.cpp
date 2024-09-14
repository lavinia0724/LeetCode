// 2024/09/14
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        string lef = bitset<32> (left).to_string(); // 00000000000000000000000000000101
        string rig = bitset<32> (right).to_string(); //00000000000000000000000000000111

        int ans = 0;
        for(int i = 0; i < 32; ++i){ // 因為題目說最大是 2^31 - 1
            if(lef[i] == rig[i]){
                // 從最左邊的位數開始，相同等於 1 的，在 left 到 right 之間也都會等於 1，但一旦其中一者為 0，後面也都不用看了，在 left 到 right 之間必會有 0 的組成
                if(lef[i] == '1') ans += pow(2, 32 - i - 1); // ex: lef[29] == rig[29] == 1, pow(2, 32 - 29 - 1) = 2^2 = 4, 
            }
            else break; // ex: lef[30] = 0 != lef[29] = 1
        }
        return ans;
    }
};