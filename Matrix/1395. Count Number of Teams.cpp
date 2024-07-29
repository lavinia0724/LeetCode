// 2024/07/29
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;

        // 大家依序當 mid，去算其依序變大和依序變小，有多少組合
        for(int mid = 0; mid < rating.size(); ++mid){
            
            int leftSmaller = 0, rightLarger = 0;
            for(int i = mid; i >= 0; --i){
                if(rating[i] < rating[mid]) leftSmaller++;
            }
            for(int i = mid + 1;i < rating.size(); ++i){
                if(rating[i] > rating[mid]) rightLarger++;
            }

            ans += leftSmaller * rightLarger; // 左到右依序變大的組合數量

            int leftLarger = 0, rightSmaller = 0;
            for(int i = mid; i >= 0; --i){
                if(rating[i] > rating[mid]) leftLarger++;
            }
            for(int i = mid + 1;i < rating.size(); ++i){
                if(rating[i] < rating[mid]) rightSmaller++;
            }

            ans += leftLarger * rightSmaller; // 左到右依序變小的組合數量
        }

        return ans;
    }
};