// 2024/12/23
struct Item{
    int num;
    int row;
    int col;

    // Add a constructor for easier initialization
    Item(int n, int r, int c) : num(n), row(r), col(c) {}
};

struct cmp{
    bool operator () (Item a, Item b){
        return a.num > b.num;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Item, vector<Item>, cmp> pq;
        int maxVal = INT_MIN, start = 0, end = INT_MAX;

        for(int i = 0; i < nums.size(); ++i){
            pq.push({nums[i][0], i, 0});
            maxVal = max(maxVal, nums[i][0]);
        }

        while(pq.size() == nums.size()){
            Item top = pq.top();
            pq.pop();
            int num = top.num, row = top.row, col = top.col;

            if(maxVal - num < end - start){
                start = num;
                end = maxVal;
            }

            if(col + 1 < nums[row].size()){
                pq.push({nums[row][col + 1], row, col + 1});
                maxVal = max(maxVal, nums[row][col + 1]);
            }
        }

        return {start, end};
    }
};

/*
nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]

init, maxVal = 5
pq = [{0, 1, 0}, {4, 0, 0}, {5, 2, 0}]

pop {0, 1, 0}, start = 0, end = 5, max = 9
pq = [{4, 0, 0}, {5, 2, 0}, {9, 1, 1}]

pop {4, 0, 0}, start = 0, end = 5, max = 10
pq = [{5, 2, 0}, {9, 1, 1}, {10, 0, 1}]

pop {5, 2, 0}, start = 0, end = 5, max = 18
pq = [{9, 1, 1}, {10, 0, 1}, {18, 2, 1}]

pop {9, 1, 1}, start = 0, end = 5, max = 18
pq = [{10, 0, 1}, {12, 1, 2}, {18, 2, 1}]

pop {10, 0, 1}, start = 0, end = 5, max = 18
pq = [{12, 1, 2}, {15, 0, 2}, {18, 2, 1}]

pop {12, 1, 2}, start = 0, end = 5, max = 20
pq = [{15, 0, 2}, {18, 2, 1}, {20, 1, 3}]

pop {15, 0, 2}, start = 0, end = 5, max = 24
pq = [{18, 2, 1}, {20, 1, 3}, {24, 0, 3}]

pop {18, 2, 1}, start = 0, end = 5, max = 24
pq = [{20, 1, 3}, {22, 2, 3}, {24, 0, 3}]

pop {20, 1, 3}, start = 20, end = 24, max = 24
pq = [{22, 2, 3}, {24, 0, 3}] -> pq.size() =/= nums.size() break

ans: {20, 24}
*/