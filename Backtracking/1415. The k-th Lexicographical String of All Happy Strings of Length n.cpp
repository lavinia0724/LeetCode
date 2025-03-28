// 2025/03/28
class Solution {
    public:
        string getHappyString(int n, int k) {
            string set = "abc";
    
            return backtracking("", set, n, k);
        }
    
        string backtracking(string nowStr, string set, int n, int& k){
            if(nowStr.size() == n) {
                k--;
                if(k == 0) return nowStr;
                return "";
            }
    
            for(int i = 0; i < set.size(); ++i){ 
                if(!nowStr.empty() && nowStr.back() == set[i]) continue;
    
                string ans = backtracking(nowStr + set[i], set, n, k);
                if(ans != "") return ans;
            }
            return "";
        }
    private:
        int counter = 0;
    };