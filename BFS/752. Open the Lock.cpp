/* 2024/04/22 */
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> used(deadends.begin(), deadends.end());

        if(used.count("0000")) return -1;
        if(target == "0000") return 0;

        queue<pair<string, int>> q;
        q.push({"0000", 0});

        while(!q.empty()){
            string nowstr = q.front().first;
            int cnt = q.front().second;
            q.pop();

            for(int i = 0; i < 4; ++i){
                // 往更大數字轉
                string tmp = nowstr;
                tmp[i] = (tmp[i] == '9' ? '0' : tmp[i] + 1);
                if(tmp == target) return cnt+1;
                if(!used.count(tmp)){
                    q.push({tmp, cnt+1});
                    used.insert(tmp);                    
                }

                // 往更小數字轉
                tmp = nowstr;
                tmp[i] = (tmp[i] == '0' ? '9' : tmp[i] - 1);
                if(tmp == target) return cnt+1;
                if(!used.count(tmp)){
                    q.push({tmp, cnt+1});
                    used.insert(tmp);                    
                }
            }
        }
        return -1;
    }
};