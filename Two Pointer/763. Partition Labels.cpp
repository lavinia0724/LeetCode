// 2025/03/30
class Solution {
    public:
        vector<int> partitionLabels(string s) {
            unordered_map<char, int> hashTable; // 紀錄每個字母第一個出現的位置和最後一個出現的位置
            for(int i = 0; i < s.size(); ++i){
                hashTable[s[i]] = i; // 每次更新最後一個出現的位置
            }
    
            vector<int> ans;
            int lastend = -1, lastsize = 0;
            for(int i = 0; i < s.size(); ++i){
                if(lastend == -1) lastend = hashTable[s[i]];
    
                if(i == lastend){
                    lastsize += (ans.empty()) ? 0 : ans[ans.size()-1]; // 獲得前一個字串範圍大小
                    ans.push_back({i+1 - lastsize}); // idx+1 才是這個範圍的 size，然後 - 前一個字串範圍的大小
                    lastend = -1;
                    continue;
                }
    
                if(hashTable[s[i]] > lastend) lastend = hashTable[s[i]];
            }
    
            return ans;
        }
    };