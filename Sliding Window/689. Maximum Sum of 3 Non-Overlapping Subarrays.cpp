//2024/12/28
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int bestFirstStart, bestFirstSum = 0;
        int bestDoubleWindowSum = 0, bestTripleWindowSum = 0;
        vector<int> bestDoubleWindow(2), bestTripleWindow(3);


        int firstStart = 0, secondStart = firstStart + k, thirdStart = secondStart + k;
        for(int i = 0; i < nums.size() - (3 * k) + 1; ++i){
            int window1 = 0, window2 = 0, window3 = 0;
            for(int j = 0; j < k; ++j){
                window1 += nums[firstStart + j];
                window2 += nums[secondStart + j];
                window3 += nums[thirdStart + j];
            }

            if(window1 > bestFirstSum){
                bestFirstSum = window1;
                bestFirstStart = firstStart;
            }

            if((bestFirstSum + window2 > bestDoubleWindowSum) && (bestFirstStart + k <= secondStart)){
                bestDoubleWindowSum = bestFirstSum + window2;
                bestDoubleWindow[0] = bestFirstStart;
                bestDoubleWindow[1] = secondStart;
            }

            if((bestDoubleWindowSum + window3 > bestTripleWindowSum) && (bestDoubleWindow[1] + k <= thirdStart)){
                bestTripleWindowSum = bestDoubleWindowSum + window3;
                bestTripleWindow[0] = bestDoubleWindow[0];
                bestTripleWindow[1] = bestDoubleWindow[1];
                bestTripleWindow[2] = thirdStart;
            }
            firstStart += 1, secondStart += 1, thirdStart += 1;
        }
        
        return bestTripleWindow;
    }
};