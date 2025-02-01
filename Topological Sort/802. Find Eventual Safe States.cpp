// 2025/01/24
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adjcentMatrix(graph.size());
        vector<int> indegree(graph.size(), 0);

        for(int i = 0; i < graph.size(); ++i){
            for(int j = 0; j < graph[i].size(); ++j){
                adjcentMatrix[graph[i][j]].push_back(i); // 倒過來，紀錄的是子節點到父節點的關係，好讓 leaf indegree 為 0 開始往祖先推
                indegree[i]++; // 父節點 degree ++
            }
        }

        queue<int> q;
        for(int i = 0; i < graph.size(); ++i)
            if(indegree[i] == 0) q.push(i); // indegree == 0 就是葉節點
        
        vector<bool> isSafe(graph.size(), false);
        while(!q.empty()){
            int now = q.front();
            q.pop();

            isSafe[now] = true; // 從葉節點一路推回來，如果沒有形成環，都會被推入 queue 中，必為 safe node

            for(auto e: adjcentMatrix[now]){
                indegree[e]--; // 砍斷現在這顆子節點(因為是往祖先回推)與父節點的關係
                if(indegree[e] == 0) q.push(e); // 這個父節點沒有其他爸爸了，他必不會形成環，可以推入 queue 中
            }
        }

        vector<int> ansSafeNode;
        for(int i = 0; i < graph.size(); ++i) if(isSafe[i]) ansSafeNode.push_back(i);

        return ansSafeNode;
    }
};