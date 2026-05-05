// 2026/05/05
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) { // 讓 n1 是比較短的那一邊
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(), n = nums2.size();
        int total = m + n, half = (total + 1) / 2;

        int left = 0, right = m; // right = m 因為這題要找 nums1 要切幾個元素到左半邊

        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = half - i; // 因為左半邊總數要等於 half，所以這樣設定 j

            int left1  = (i == 0) ? INT_MIN : nums1[i - 1]; // num1 的左半邊最大值
            int right1 = (i == m) ? INT_MAX : nums1[i]; // num1 的右半邊最小值

            int left2  = (j == 0) ? INT_MIN : nums2[j - 1]; // num2 的左半邊最大值
            int right2 = (j == n) ? INT_MAX : nums2[j]; // num2 的 右半邊最小值

            if (left1 <= right2 && left2 <= right1) { // 代表左半邊全部 <= 右半邊全部
                if (total % 2 == 1) { // 成立之就直接算 median
                    return max(left1, left2); // 如果 total 長度是奇數，找整個左半邊的最大值
                }

                // 如果total 長度是偶數，找整個左半邊的最大值和整個右半邊的最小值的平均
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }

            if (left1 > right2) { // nums1 左邊拿太多了
                right = i - 1; // 所以少拿一點
            } else {
                left = i + 1; // 否則多拿一點
            }
        }

        return 0.0;
    }
};