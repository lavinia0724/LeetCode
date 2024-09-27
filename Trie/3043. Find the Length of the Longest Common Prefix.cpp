// 2024/09/24
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> arr1Prefixes;
        for(int val: arr1){
            while(!arr1Prefixes.count(val) && val > 0){
                arr1Prefixes.insert(val);
                val /= 10;
            }
        }

        int longestPrefix = 0;
        for(int val: arr2){
            while(!arr1Prefixes.count(val) && val > 0) val /= 10;

            if(val > 0){
                string strVal = to_string(val);
                longestPrefix = max(longestPrefix, static_cast<int>(strVal.size()));
            }
        }

        return longestPrefix;
    }
};

/*
arr1 = [1,10,100], arr2 = [1000]

arr1Prefixes:
insert -> 100,  then 100 /= 10
insert -> 10,   then 10 /= 10
insert -> 1,    then 1 /= 10

final arr1Prefixes: [1000, 100, 10, 1]

for(int val: arr2), val = 1000

while(!arr1Prefixes.count(val) && val > 0) val /= 10
because 1000 is not in arr1Prefixes, then val /= 10, val = 100, 100 is in arr1Prefixes

100 to string -> "100"
and then longestPrefix update to string "100"'s size = 3

ans: 3
*/