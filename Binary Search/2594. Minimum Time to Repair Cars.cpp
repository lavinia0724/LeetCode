// 2025/04/03
class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            long long int miniRank = *min_element(ranks.begin(), ranks.end());
            long long int maxiRank = *max_element(ranks.begin(), ranks.end());
            long long int left = 1, right = miniRank * cars * cars;
    
            unordered_map<int, int> rankFrequence;
            for(auto rank: ranks) rankFrequence[rank]++;
    
            long long int eachMechanicsTime = binarySearch(left, right, rankFrequence, cars);
            return eachMechanicsTime;
        }
    
        long long int binarySearch(long long int left, long long int right, unordered_map<int, int> rankFrequence, int cars){
            if(left >= right) return left;
    
            long long int mid = (left + right) / 2;
            long long int totalCarsRepair = 0;
            for(auto [rank, cnt]: rankFrequence) totalCarsRepair += cnt * (long long)sqrt(mid / rank);
    
            if(totalCarsRepair >= cars) return binarySearch(left, mid, rankFrequence, cars);
            else  return binarySearch(mid + 1, right, rankFrequence, cars);
    
        }
    };