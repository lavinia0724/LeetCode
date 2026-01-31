// 2026/01/31
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        while(left < right){
            int mid = (left + right) >> 1;
            if(letters[mid] > target) right = mid;
            else left = mid + 1;
        }
        if(letters[left % letters.size()] > target) return letters[left % letters.size()];
        return letters[0];
    }
};