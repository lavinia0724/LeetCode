// 2026/03/12
class Solution {
public:
    struct DSU { // Disjoint Set Union
        vector<int> p, r;
        DSU(int n) {
            p.resize(n);
            r.resize(n, 0);
            for(int i = 0; i < n; i++) p[i] = i;
        }

        int find(int x){
            if(p[x] != x) p[x] = find(p[x]);
            return p[x];
        }

        bool unite(int a,int b){
            a = find(a);
            b = find(b);
            if(a == b) return false;

            if(r[a] < r[b]) swap(a,b);
            p[b] = a;
            if(r[a] == r[b]) r[a]++;
            return true;
        }
    };

    bool check(int n, vector<vector<int>>& must, vector<vector<int>>& opt, int k, int target){
        DSU dsu(n);
        int used = 0;
        int upgrades = 0;

        // must edges
        for (auto &e : must) {
            int u = e[0];
            int v = e[1];
            int s = e[2];
            if (s < target) return false;
            if (!dsu.unite(u, v)) return false;
            used++;
        }

        // optional edges without upgrade
        for (auto &e : opt) {
            int u = e[0];
            int v = e[1];
            int s = e[2];
            if (s < target) continue;
            if (dsu.unite(u, v)) used++;
        }

        // optional edges with upgrade
        for (auto &e : opt) {
            int u = e[0];
            int v = e[1];
            int s = e[2];
            if (s >= target) continue;
            if (s * 2 < target) continue;
            if (upgrades == k) break;
            if (dsu.unite(u, v)) {
                upgrades++;
                used++;
            }
        }
        return used == n - 1;
    }

    int maxStability(int n, vector<vector<int>> &edges, int k) {
        vector<vector<int>> must;
        vector<vector<int>> opt;

        for (auto &e : edges) {
            if (e[3] == 1) must.push_back({ e[0], e[1], e[2] });
            else opt.push_back({ e[0], e[1], e[2] });
        }

        int left = 0;
        int right = 200000;
        int ans = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(n, must, opt, k, mid)) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};