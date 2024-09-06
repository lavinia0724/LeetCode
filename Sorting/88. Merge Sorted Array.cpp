// 2024/09/06
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m - 1, j = n - 1, idx = m + n - 1; j >= 0; --idx){
            if(i >= 0 && nums1[i] > nums2[j]) nums1[idx] = nums1[i--];
            else nums1[idx] = nums2[j--];
        }
    }
};