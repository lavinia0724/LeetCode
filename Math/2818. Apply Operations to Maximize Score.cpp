// 2025/03/29
// 這題不用快速冪會 TLE 過不了
class Solution {
    public:
        const long long int mod = 1e9 + 7;
    
        int maximumScore(vector<int>& nums, int k) {
            priority_queue<pair<int, int>> pq;
            for(int i = 0; i < nums.size(); ++i) pq.push({nums[i], i});
            
            vector<int> primeScore(nums.size(), 0);
            for(int i = 0; i < nums.size(); ++i){
                int num = nums[i];
    
                for(int prime = 2; prime <= sqrt(num); ++prime){
                    if(num % prime == 0){
                        primeScore[i]++;
                        while(num % prime == 0) num /= prime;
                    }
                }
                if(num >= 2) primeScore[i]++; // 代表最後除完的 num 也是一個 prime
            }
    
            stack<int> stk;
            vector<long long int> leftRegion(nums.size(), -1), rightRegion(nums.size(), nums.size()); // -1 開始因為 idx 0 - -1 = 1 才會等於實際範圍
            for(int i = 0; i < nums.size(); ++i){
                while(!stk.empty() && primeScore[i] > primeScore[stk.top()]) {
                    int leftTopidx = stk.top();
                    stk.pop();
                    rightRegion[leftTopidx] = i; // 順便把前面比較小的 idx 的 rightReigon 都改成自己
                }
                if(!stk.empty()) leftRegion[i] = stk.top(); // stk top 是目前數字的 primeScore 無法比他大的最左邊的 idx
                stk.push(i);
            }
    
            vector<long long int> numOfSubarray(nums.size());
            for(int i = 0; i < nums.size(); ++i){
                numOfSubarray[i] = (rightRegion[i] - i) * (i - leftRegion[i]);
            }
    
            long long int ans = 1;
            while(k > 0){
                auto topNum = pq.top();
                pq.pop();
    
                long long int topNumOfSubarray = numOfSubarray[topNum.second];
                ans = (ans * power(topNum.first, min((long long int)k, topNumOfSubarray))) % mod;
    
                k -= min((long long int)k, topNumOfSubarray);
            }
    
            return ans;
        }
    
        long long int power(long long int base, long long int exponent){
            long long int score = 1;
            while(exponent > 0){
                if(exponent % 2 == 1) score = (score * base) % mod;
                base = (base * base) % mod;
                exponent /= 2; 
            }
            return score;
        }
        /*
        ex: base = 3, exponent = 3
        
        exponent % 2 == 1 -> score = 1 * 3
        base = 3 * 3 = 9
        exponent /= 3 -> 1 其實就是 exponent 要 -1，但如果 exponent 不是 2 的倍數這裡直接除會少 1，所以前面才要那個 if 來把 score 乘進去
        */
    
    };