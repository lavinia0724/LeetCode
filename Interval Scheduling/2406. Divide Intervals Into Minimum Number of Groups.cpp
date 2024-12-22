// 2024/12/22
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> intervalsEnd;
        for(vector<int> interval: intervals){
            intervalsEnd.push_back({interval[0], 1});
            intervalsEnd.push_back({interval[1] + 1, -1});
        }

        sort(intervalsEnd.begin(), intervalsEnd.end());

        int current = 0;
        int maxGroup = 0;
        for(auto pair: intervalsEnd){
            current += pair.second;
            maxGroup = max(maxGroup, current);
        }

        return maxGroup;
    }
};

/*
intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
intervalsEnd:
[5, 1], [11, -1], [6, 1], [9, -1], [1, 1], [6, -1], [2, 1], [4, -1], [1, 1], [11, -1]

after sort:
[1, 1], [1, 1], [2, 1], [4, -1], [5, 1], [6, -1], [6, 1], [9, -1], [11, -1], [11, -1]

current = 0 + 1 = 1
[1, 1]

current = 1 + 1 = 2
[1, 1]
[1, 1]

current = 2 + 1 = 3
[1, 1]
[1, 1]
[2, 1]

current = 3 - 1 = 2, max(maxGroup, current) = 3
[1, 1]
[1, 1]
[2, 1], [4, -1]

current = 2 + 1 = 3, max(maxGroup, current) = 3
[1, 1]
[1, 1]
[2, 1], [4, -1], [5, 1]

current = 3 - 1 = 2, max(maxGroup, current) = 3
[1, 1], [6, -1]
[1, 1]
[2, 1], [4, -1], [5, 1]

current = 2 + 1 = 3, max(maxGroup, current) = 3
[1, 1], [6, -1], [6, 1]
[1, 1]
[2, 1], [4, -1], [5, 1]

current = 3 - 1 = 2, max(maxGroup, current) = 3
[1, 1], [6, -1], [6, 1]
[1, 1]
[2, 1], [4, -1], [5, 1], [9, -1]

current = 2 - 1 = 1, max(maxGroup, current) = 3
[1, 1], [6, -1], [6, 1], [11, -1]
[1, 1]
[2, 1], [4, -1], [5, 1], [9, -1]

current = 1 - 1 = 0, max(maxGroup, current) = 3
[1, 1], [6, -1], [6, 1], [11, -1]
[1, 1], [11, -1]
[2, 1], [4, -1], [5, 1], [9, -1]
*/