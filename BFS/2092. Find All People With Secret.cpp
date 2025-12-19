// 2025/12/19
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // 依照時間排序
        sort(meetings.begin(), meetings.end(), cmp);

        // 記錄誰已經知道秘密
        vector<bool> know(n, false);
        know[0] = true;
        know[firstPerson] = true;

        int m = meetings.size();
        // 逐個時間點處理
        for(int i = 0; i < m;) {
            int t = meetings[i][2];

            // 同一時間的 meeting 範圍 [i, j)
            int j = i;
            while (j < m && meetings[j][2] == t)  j++;

            // 建立在這個時間範圍內的會議有哪些人以及他們之間的關係
            unordered_map<int, vector<int>> graph; // 建這些人的關係圖，等等要 BFS
            unordered_set<int> people;
            for (int k = i; k < j; k++) {
                int x = meetings[k][0];
                int y = meetings[k][1];
                graph[x].push_back(y);
                graph[y].push_back(x);
                people.insert(x);
                people.insert(y);
            }

            // 從原本就知道秘密的人開始 BFS
            queue<int> q;
            unordered_set<int> visited;
            for (int p : people) {
                if (know[p]) {
                    q.push(p);
                    visited.insert(p);
                }
            }

            // BFS 這些知道秘密的人這段時間接觸的人們
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : graph[u]) {
                    if (!visited.count(v)) {
                        visited.insert(v);
                        q.push(v);
                    }
                }
            }

            // BFS 到的人，這個時間點後知道秘密
            for (int p : visited)  know[p] = true;
            i = j;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (know[i]) ans.push_back(i);
        }
        return ans;
    }
};