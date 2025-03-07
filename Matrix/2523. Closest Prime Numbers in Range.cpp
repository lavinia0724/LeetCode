// 2025/03/07
class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            int prevPrime = -1, primeNum1 = -1, primeNum2 = -1, miniDist = INT_MAX;
            if((left == 1 && right >= 3) || (left == 2 && right >= 3)) return {2, 3};  
    
            if(left % 2 == 0) left += 1;
            for(int candidate = left; candidate <= right; candidate += 2){
                if(isPrime(candidate)){
                    if(prevPrime != -1){
                        if(candidate - prevPrime < miniDist) {
                            miniDist = candidate - prevPrime;
                            primeNum2 = candidate;
                            primeNum1 = prevPrime;
                        }
                    }
                    prevPrime = candidate;
                }
            }
            vector<int> ans(2);
            if(primeNum1 == -1 || primeNum2 == -1) return {-1, -1};
            ans[0] = primeNum1;
            ans[1] = primeNum2;
            return ans;
        }
    
        bool isPrime(int n){
            if(n <= 1 || n % 2 == 0) return false;
            if(n == 2) return true;
            for(int i = 3; i <= sqrt(n); i += 2){
                if(n % i == 0) return false;
            }
            return true;
        }
    };