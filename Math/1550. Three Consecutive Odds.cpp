// 2024/07/07
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int check = 0;
        for(int i = 0; i < arr.size(); ++i){
            if(arr[i] % 2 != 0) check++;
            else check = 0;

            if(check == 3) return true;
        }
        return false;
    }
};

// ----------------------------------------------------------------

// 2025/05/11
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for(auto num: arr){
            if(num & 1) cnt++;
            else cnt = 0;
            if(cnt == 3) return true;
        }
        return false;
    }
};