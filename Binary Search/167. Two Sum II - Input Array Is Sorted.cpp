// 2024/09/12
class Solution {
public:
    int binarySearch(vector<int>& numbers, int left, int right, int target, int origin){ // origin 用於紀錄避免找到相同 idx
        if(left > right) return -1;
        int mid = (left + right) >> 1;
        
        if(numbers[mid] == target && mid != origin) return mid;

        if(numbers[mid] > target) return binarySearch(numbers, left, mid-1, target, origin);
        else return binarySearch(numbers, mid+1, right, target, origin);
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); ++i){
            int idx = binarySearch(numbers, i, numbers.size()-1, target - numbers[i], i);
            if(idx != -1) return {i+1, idx+1};
        }
        return {};
    }
};