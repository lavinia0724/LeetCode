// 2025/03/27
class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            unordered_map<int, int> numCnt;
            int nowDominant = 0;
            for(int i = 0; i < nums.size(); ++i){ 
                // 跑一次 arr，確認從頭到現在的 idx 為止，誰是出現數量最多的數字 (因為最後的 Dominant 一定是整個 arr 出現最多次的數)
                // 因為他切兩個子 arr，兩邊分別過半，兩個子 arr 數量加起來後整個 arr 肯定也會過半
                numCnt[nums[i]]++;
                if(numCnt[nowDominant] < numCnt[nums[i]]) nowDominant = nums[i];
            }
    
            vector<int> dominant(nums.size());
            dominant[0] = (nums[0] == nowDominant ? 1 : 0);
            for(int i = 1; i < nums.size(); ++i){ // 去算 dominant 從頭到該 idx 目前已出現幾次
                dominant[i] = dominant[i-1];
                if(nums[i] == nowDominant) dominant[i] += 1;
            }
            
            for(int i = 0; i < nums.size()-1; ++i){ // 去遍歷試能切在哪
                // 切在 idx = i 的情況
                // dominant[nums.size()-1] - dominant[i] > double((nums.size() - (i+1))/2) 右邊子 arr 範圍的 dominant 數量 > 此範圍長度的一半
                // dominant[i] > double((i+1))/2) 左邊子 arr 範圍的 dominant 數量 > 此範圍長度的一半
                if(dominant[nums.size()-1] - dominant[i] > double((nums.size() - (i+1)))/2 && dominant[i] > double(i+1)/2) return i;
            }
            return -1;
        }
    };