/* 2024/04/23
觀念參考自: https://home.gamer.com.tw/artwork.php?sn=5478747
不斷刪除最外層的葉節點，直到剩下最中間的樹枝（可能1或2個點）*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        deque<int> G[n];
        int degree[n]; // 該點與多少點連接
        memset(degree, 0, sizeof(degree));

        for(int i = 0; i < edges.size(); ++i){
            // 雙向圖
            G[edges[i][0]].emplace_back(edges[i][1]);
            G[edges[i][1]].emplace_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }

        int used = n;
        vector<int> leaves, nxtLeaves;
        // degree == 1 代表是葉節點
        for(int i = 0; i < n; ++i)
            if(degree[i] == 1) leaves.push_back(i);

        while(used > 2){
            nxtLeaves.clear();
            for(int i = 0; i < leaves.size(); ++i){
                // 所有與葉節點相連的節點 degree--，刪除與葉節點相連的邊
                for(int j = 0; j < G[leaves[i]].size(); ++j){ 
                    degree[G[leaves[i]][j]]--;
                    // 如果刪除完後的相連節點變成新的最外層葉節點，加入下次要處理的葉節點
                    if(degree[G[leaves[i]][j]] == 1) nxtLeaves.push_back(G[leaves[i]][j]);
                }
                used--;
            }
            leaves = nxtLeaves;
        }
        
        if(n == 1 && edges.size() == 0) leaves.push_back(0);
        return leaves;
    }
};