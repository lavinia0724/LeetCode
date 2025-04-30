// 2025/04/30
class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int mini = 0, maxi = 0, nownum = 0;
            for(auto difference: differences){
                nownum += difference;
                mini = min(mini, nownum);
                maxi = max(maxi, nownum);
                if(maxi - mini > upper - lower) return 0;
            }
            return (upper - lower) - (maxi - mini) + 1;
        }
    };
    
    /*
    公式: lower <= x + mini && x + maxi <= upper
    因此: lower-mini <= x(陣列的起始值) <= upper-maxi
    可得: upper-maxi-lower-(-mini) + 1 = x 可能陣列起始值的數量
    
    differences = [1,-3,4], lower = 1, upper = 6
    
    difference: 1
    nownum = 0 + 1 = 1
    mini = min() = 0
    maxi = max() = 1
    maxi - mini = 1
    
    difference: -3
    nownum = 1 + -3 = -2
    mini = min() = -2 
    maxi = max() = 1  
    maxi - mini = 3
    
    difference: 4
    nownum = -2 + 4 = 2
    mini = min() = -2 
    maxi = max() = 2  
    maxi - mini = 4
    
    (upper - lower) - (maxi - mini) + 1 = (6 - 1) - (2 - -2) + 1 = 2
    */