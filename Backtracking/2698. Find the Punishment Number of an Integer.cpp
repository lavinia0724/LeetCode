// 2025/02/15
class Solution {
    public:
        bool canPartition(string stringNum, int target){
            if(stringNum == "" && target == 0) return true;
            if(target < 0) return false;
            
            for(int i = 0; i < stringNum.size(); ++i){
                string left = stringNum.substr(0, i + 1); // 確認切從頭到 i 的左邊 ex: 1296 -> 1 (left) | 296 (right)
                string right = stringNum.substr(i + 1);
    
                if(canPartition(right, target - stoi(left))) return true; // 確認 ex: right: 296, left: target 36 - 1 = 35
            }
            return false;
        }
    
        int punishmentNumber(int n) {
            int punishmentNum = 0;
            for(int currNum = 1; currNum <= n; currNum++){
                int squareNum = currNum * currNum; // 遍歷所有 [1, n] 的數字的平方數
    
                if(canPartition(to_string(squareNum), currNum)) punishmentNum += squareNum;
            }
            return punishmentNum;
        }
    };
    
    /*
    canPartition(1296, 36)
    squareNum: 1296, target: 36
    i = 0
    left: 1    -> target: 36 - 1 = 35
    right: 296 -> squareNum
    
    canPartition(296, 35)
    squareNum: 296, target: 35
    i = 0
    left: 2    -> target: 35 - 2 = 33
    right: 96  -> squareNum
    
    canPartition(96, 33)
    squareNum: 96, target: 33
    i = 0
    left: 9    -> target: 33 - 9 = 24
    right: 6   -> squareNum
    
    
    canPartition(6, 24)
    num < target return false
    
    canPartition(96, 33)
    squareNum: 96, target: 33
    i = 1
    left: 96    -> target: 33 - 96 = -33 --> 負的 return false
    right:      -> squareNum
    
    canPartition(296, 35)
    squareNum: 296, target: 35
    i = 1
    left: 29    -> target: 35 - 29 = 6 
    right: 6    -> squareNum
    
    canPartition(6, 6)
    squareNum: 6, target: 6
    i = 0
    left: 6    -> target: 6 - 6 = 0 -- > == 0 return true 
    right:     -> squareNum
    
    也就是可以切 1 | 29 | 6
    1 + 29 + 6 = 36 == currNum
    */