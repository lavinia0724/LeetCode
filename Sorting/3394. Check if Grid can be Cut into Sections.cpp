// 2025/03/25
class Solution {
    public:
        bool checkIfCutable(int n, unordered_map<int, int> mp, priority_queue<int, vector<int>, greater<int>> pq){
            int cut = 0;
            int cutNum = 0;
            while(!pq.empty()){
                int start = pq.top();
                pq.pop();
                
                if(start >= cut) {
                    cutNum++; // 多切幾刀也無所謂
                    cut = mp[start];
                }
                else if(start < cut && mp[start] <= cut) continue;
                else {
                    cut = max(cut, mp[start]); // 改成切在你的 end，這樣 cutNum 也不會變
                    if(pq.empty()) return false; // 即便這刀切在你的 end，你後面沒有其他 rectangle 了也不行，每個 cut 區間都必須至少有一 rectangle
                }
                if(cut == n && cutNum <= 2) return false; // 不能 cut 在範圍的邊上所以要少一刀，但如果不夠刀就 false
            }
            return cutNum >= 2;
        }
    
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            unordered_map<int, int> horizonMp, verticalMp;
            priority_queue<int, vector<int>, greater<int>> horizonQ, verticalQ;
            for(auto nodes: rectangles){
                if(horizonMp.count(nodes[1]) == 0){
                    horizonMp[nodes[1]] = nodes[3];
                    horizonQ.push(nodes[1]);
                }
                else horizonMp[nodes[1]] = max(horizonMp[nodes[1]], nodes[3]);
    
                if(verticalMp.count(nodes[0]) == 0){
                    verticalMp[nodes[0]] = nodes[2];
                    verticalQ.push(nodes[0]);
                }
                else verticalMp[nodes[0]] = max(verticalMp[nodes[0]], nodes[2]);
            }
    
            // 判斷 horizon 是否可切兩刀
            if(checkIfCutable(n, horizonMp, horizonQ)) return true;
    
            // 判斷 vertical 是否可切兩刀
            if(checkIfCutable(n, verticalMp, verticalQ)) return true;
    
            return false;
        }
    };