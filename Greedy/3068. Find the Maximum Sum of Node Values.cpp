/* 2024/05/19 */
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // 在這題之中，有沒有連接邊並不重要，重要是取每個點 xor 的值
        // 如果 xor 的值大於原本的值，就加入 ansSum，反之，則不加入
        // 若總 xor 後較大的結點數為奇數，則要評估 xor 後較小的數中減少量最小者，其與 xor 後較大的數中增加最小者，如果增加的幅度大於減少的幅度，則兩者納入 ansSum，否則都不納入   
        int cnt = 0;
        long long int ansSum = 0;
        long long int minXorLargerNum = 0x3f3f3f3f, minXorSmallerNum = -0x3f3f3f3f;
        for(int i = 0; i < nums.size(); ++i){
            long long int tmp = nums[i] ^ k;
            long long int difference = tmp - nums[i];
            if(difference > 0){
                ansSum += tmp;
                minXorLargerNum = min(minXorLargerNum, difference);
                cnt++;
            }
            if(difference < 0){
                ansSum += nums[i];
                minXorSmallerNum = max(minXorSmallerNum, difference);
            }
        }

        if(cnt & 1){
            if((minXorLargerNum + minXorSmallerNum) > 0){
                ansSum += minXorSmallerNum;
            }
            else{
                ansSum -= minXorLargerNum;
            }
        }
        return ansSum;
    }
};