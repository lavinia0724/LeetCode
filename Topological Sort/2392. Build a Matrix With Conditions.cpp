// 2024/07/25
class Solution {
public:
    vector<int> topologicalSort(int k, vector<vector<int>>& conditions){
        vector<int> indegree(k+1);
        vector<vector<int>> next(k+1);

        for(auto& it: conditions){
            next[it[0]].emplace_back(it[1]); // 把後者皆在前者後
            indegree[it[1]] += 1; // 在下面的 degree +1
        }

        // q 裡面放的是可以當 root 的點, 前面沒有任何點，故其 indegree 為 0
        queue<int> q;
        for(int i = 1; i <= k; ++i){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> rets;
        while(!q.empty()){
            int current = q.front();
            q.pop();
            rets.emplace_back(current);

            for(auto it: next[current]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it); // 前面的點都處理完了，自己也可以變成新的 root 了，推入 q
            }
        }

        // 如果有無法成形唯一的矩陣，唯一可能是條件中出現了迴圈，ex: 1 -> 2, 2 -> 3, 3 -> 1
        if (rets.size() != k) return {};

        return rets;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // 當題目條件為: 就是在問拓樸排序
        vector<int> row = topologicalSort(k, rowConditions);
        vector<int> col = topologicalSort(k, colConditions);

        if (row.empty() || col.empty()) return {};

        // 整理 k+1 * k+1 的矩陣
        // ex: row, 假設順序為 3 -> 1 -> 2 -> 4, 則依序將 3 放在 row idx = 0, 1 放在 row idx = 1, 2 放在 row idx = 2, 4 放在 row idx = 3
        // ex: col, 假設順序為 2 -> 3 -> 1 -> 4, 則依序將 2 放在 col idx = 0, 3 放在 col idx = 1, 1 放在 col idx = 2, 4 放在 col idx = 3
        vector<pair<int, int>> position(k+1);
        for(int i = 0; i < k; ++i) position[row[i]].first = i;
        for(int i = 0; i < k; ++i) position[col[i]].second = i;

        // 劃出答案需要的 matrix 且符合型態
        vector<vector<int>> matrix (k, vector<int> (k));
        for(int i = 1; i <= k; ++i){
            matrix[position[i].first][position[i].second] = i;
        }

        return matrix;
    }
};