// 2025/03/03
class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            vector<vector<int>> ans;
            for(int i = 0, j = 0; ;){
                if(i == nums1.size()){
                    while(j < nums2.size()){
                        ans.push_back({nums2[j][0], nums2[j][1]});
                        j++;
                    }
                    break;
                }
                else if(j == nums2.size()){
                    while(i < nums1.size()){
                        ans.push_back({nums1[i][0], nums1[i][1]});
                        i++;
                    }
                    break;
                }
    
                if(nums1[i][0] < nums2[j][0]) {
                    ans.push_back({nums1[i][0], nums1[i][1]});
                    i++;
                }
                else if(nums1[i][0] > nums2[j][0]) {
                    ans.push_back({nums2[j][0], nums2[j][1]});
                    j++;
                }
                else{
                    ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                    i++;
                    j++;
                }
            }
            return ans;
        }
    };