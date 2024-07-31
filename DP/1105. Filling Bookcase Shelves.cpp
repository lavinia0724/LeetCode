// 2024/07/31
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int f[books.size()+5];
        f[0] = 0;

        for(int i = 1; i <= books.size(); ++i){
            int w = books[i-1][0], h = books[i-1][1];
            f[i] = f[i-1] + h;
            for(int j = i-1; j > 0; --j){
                w += books[j-1][0];
                if(w > shelfWidth) break;

                h = max(h, books[j-1][1]);
                f[i] = min(f[i], f[j-1] + h);
            }
        }
        return f[books.size()];
    }
};
/*
ex: [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]]

i = 1, w = 1, h = 1
f = 0, 1

i = 2, w = 2, h = 3
f = 0, 1, 4 
j = 1, w = 2 + 1 = 3, h = max(h, 1) = 3, f[2] = min(4, 0 + 3) = 3
f = 0, 1, 3

i = 3, w = 2, h = 3
f = 0, 1, 3, 6
j = 2, w = 2 + 2 = 4, h = max(h, 3) = 3, f[3] = min(6, 1 + 3) = 4
f = 0, 1, 3, 4
j = 1, w = 4 + 1 > shelfWidth
break

i = 4, w = 1, h = 1
f = 0, 1, 3, 4, 5
j = 3, w = 1 + 2 = 3, h = max(h, 3) = 3, f[4] = min(5, 4 + 3) = 5
f = 0, 1, 3, 4, 5
j = 2, w = 3 + 2 = 5 > shelfWidth
break

i = 5, w = 1, h = 1
f = 0, 1, 3, 4, 5, 6
j = 4, w = 1 + 1 = 2, h = max(h, 1) = 1, f[5] = min(6, 4 + 1) = 5
f = 0, 1, 3, 4, 5, 5
j = 3, w = 2 + 2 = 4, h = max(h, 3) = 3, f[5] = min(5, 3 + 3) = 5
f = 0, 1, 3, 4, 5, 5
j = 2, w = 4 + 2 = 6 > selfWidth
break

i = 6, w = 1, h = 1
f = 0, 1, 3, 4, 5, 5, 6
j = 5, w = 1 + 1 = 2, h = max(h, 1) = 1, f[6] = min(6, 5 + 1) = 6
f = 0, 1, 3, 4, 5, 5, 6
j = 4, w = 2 + 1 = 3, h = max(h, 1) = 1, f[6] = min(6, 4 + 1) = 5
f = 0, 1, 3, 4, 5, 5, 5
j = 3, w = 3 + 2 = 5 > selfWidth
break

i = 7, w = 1, h = 2
f = 0, 1, 3, 4, 5, 5, 5, 7
j = 6, w = 1 + 1 = 2, h = max(h, 1) = 2, f[7] = min(5, 5 + 2) = 5
f = 0, 1, 3, 4, 5, 5, 5, 5
j = 5, w = 2 + 1 = 3, h = max(h, 1) = 2, f[7] = min(5, 5 + 2) = 5
f = 0, 1, 3, 4, 5, 5, 5, 5
j = 4, w = 3 + 1 = 4, h = max(h, 1) = 2, f[7] = min(5, 4 + 2) = 5
f = 0, 1, 3, 4, 5, 5, 5, 5
j = 5, w = 4 + 2 = 6 > selfWidth
break
*/