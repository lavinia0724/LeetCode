// 2025/02/16
class Solution {
    public:   
        vector<int> constructDistancedSequence(int n) {
            vector<int> resultSeq(n * 2 - 1, 0);
            vector<bool> UsedNum(n + 1, false);
    
            backtracking(0, resultSeq, UsedNum, n);
            return resultSeq;
        }
    private:
        bool backtracking(int currIdx, vector<int>& resultSeq, vector<bool>& UsedNum, int n){
            while(currIdx < resultSeq.size() && resultSeq[currIdx] != 0) currIdx++;
            if(currIdx == resultSeq.size()) return true;
    
    
            for(int i = n; i >= 1; --i){
                if(UsedNum[i]) continue;
    
                if(i == 1){
                    resultSeq[currIdx] = 1;
                    UsedNum[1] = true;
                    if(backtracking(currIdx + 1, resultSeq, UsedNum, n)) return true;
                    resultSeq[currIdx] = 0;
                    UsedNum[1] = false;
                }
                else if(currIdx + i < resultSeq.size() && resultSeq[currIdx + i] == 0){
                    resultSeq[currIdx] = i;
                    resultSeq[currIdx + i] = i;
                    UsedNum[i] = true;
                    if(backtracking(currIdx + 1, resultSeq, UsedNum, n)) return true;
                    resultSeq[currIdx] = 0;
                    resultSeq[currIdx + i] = 0;
                    UsedNum[i] = false;
                }
            }
            return false;
        }
    };
    /*
    n = 3
    resultSeq[0, 0, 0, 0, 0], UsedNum[f, f, f, f], currIdx = 0
    
    backtracking currIdx 0
    i = 3 -> else if
    resultSeq[3, 0, 0, 3, 0], UsedNum[f, f, f, t] -> backtracking
    
    backtracking currIdx 1
    i = 3 -> continue
    i = 2 -> resultSeq[currIdx + i] != 0 continue
    i = 1 -> if
    resultSeq[3, 1, 0, 3, 0], UsedNum[f, t, f, t] -> backtracking
    
    backtracking currIdx 2
    i = 3 -> UsedNum[i] continue
    i = 2 -> else if
    resultSeq[3, 1, 2, 3, 2], UsedNum[f, t, t, t] -> backtracking
    
    while(currIdx < resultSeq.size() && resultSeq[currIdx] != 0) currIdx++;
    if(currIdx == resultSeq.size()) return true;
    
    return true
    */