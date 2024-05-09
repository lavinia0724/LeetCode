/* 2024/05/09 */
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());

        long long int happinessvalue = 0;
        for(int i = 0; i < k; ++i){
            happinessvalue += max(happiness[i] - i, 0);
            if(happiness[i] - i < 0) break;
        }
        return happinessvalue;
    }
};