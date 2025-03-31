// 2025/03/31
class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            priority_queue<int> maxiPairWeights; 
            priority_queue<int, vector<int>, greater<int>> miniPairWeights;
            for(int i = 1; i < weights.size(); ++i){
                // 把每兩格之間當作要切的點，然後一邊會是尾，一邊會是頭，但因為題目頭尾都要 +，所以沒差
                maxiPairWeights.push(weights[i] + weights[i-1]); 
                miniPairWeights.push(weights[i] + weights[i-1]);
            }
    
            long long int ans = 0;
            while(k-- > 1){ // 取最大的那 k-1 個頭尾 和 取最小的那 k-1 個頭尾
                ans += maxiPairWeights.top() - miniPairWeights.top(); 
                maxiPairWeights.pop();
                miniPairWeights.pop();
            }
            // 頭尾雖然應該要 + 進去，但反正 maxi mini 互減會把頭尾減掉，所以不用特別計算
    
            return ans;
        }
    };