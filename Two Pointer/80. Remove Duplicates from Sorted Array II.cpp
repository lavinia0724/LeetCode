// 2024/09/07
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        
        int k = 2;
        for(int i = 2; i < nums.size(); ++i){
            if(nums[i] != nums[k-2]){
                nums[k] = nums[i];
                ++k;
            }
        }
        return k;
    }
};

/*
[0,0,1,1,1,1,2,3,3]
i = 2, k = 2
(nums[i] = 1) != (nums[k-2] = 0)
nums[2] = nums[2] = 1
k++ -> k = 3

i = 3, k = 3
same as i = 2
k++ -> k = 4
...

i = 4, k = 4
(nums[i] = 1) == (nums[k-2] = 1)
k 不加加了

i = 5, k = 4
(nums[i] = 1) == (nums[k-2] = 1)
k 不加加

i = 6, k = 4
(nums[i] = 2) != (nums[k-2] = 1)
nums[4] = nums[6] = 2
k++ -> k = 5

i = 7, k = 5
(nums[i] = 3) != (nums[k-2] = 1)
nums[5] = nums[7] = 3
k++ -> k = 6

i = 8, k = 6
(nums[i] = 3) != (nums[k-2] = 1)
nums[6] = nums[8] = 3
k++ -> k = 7

return k = 7
*/