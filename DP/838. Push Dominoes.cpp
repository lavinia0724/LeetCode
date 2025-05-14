// 2025/05/14
class Solution {
public:
    string pushDominoes(string dominoes) {
        string ans = dominoes;
        int lastLeft = 0, lastRight = -1;
        for(int i = 0; i < dominoes.size(); ++i){
            if(dominoes[i] == 'R') {  
                if(lastRight != -1){ // 一定是 R.....R 的 case；不包含 .....R (而且這個 case 也不用更新)
                    for(int lef = lastRight + 1; lef < i; lef++){ // 更新所有 LastRight 到 Right 之間的 . 變成 R
                        dominoes[lef] = 'R';
                    }
                }
                lastRight = i; // 現在最左邊的 R 是 i
            }
            else if(dominoes[i] == 'L'){
                if(lastRight != -1){ // R......L 的 case，我現在來到了這個右邊的 L，lastRight 裡記錄著剛剛最左邊的 R 的位址
                    for(int lef = lastRight + 1, rig = i - 1; lef < rig; lef++, rig--){ // 更新 R 到 L 中間的每個 .，同時更新
                        dominoes[lef] = 'R';
                        dominoes[rig] = 'L';
                    }
                    lastRight = -1; // 現在沒有最左邊的 R 了
                }
                else { // L.....L (其實這個也不用更新) 或 ......L 的 case
                    for(int lef = lastLeft; lef < i; ++lef) dominoes[lef] = 'L'; // 更新所有 lastLeft 到現在的 i 之間的 . 變成 L
                }
                lastLeft = i;
            }
        }

        if(lastRight != -1){
            for(int i = lastRight + 1; i < dominoes.size(); i++){ // 把最後的 R..... 的 case 也更新完
                dominoes[i] = 'R';
            }
        }
        return dominoes;
    }
};