/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#define findMedianSortedArrays find_median_sorted_arrays

class Solution {
  public:
    /**
     * T = O(log(min(N1, N2)))
     * S = O(1)
     * 
     * N1 = length of nums1
     * N2 = length of nums2
     */
    double find_median_sorted_arrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n = n1 + n2;
        int m = (n + 1) / 2;
        int l = 0, r = n1;

        while (l <= r) {
            int c1 = (l + r) / 2;
            int c2 = (m - c1);

            int l1 = (c1 == 0) ? INT_MIN : nums1[c1 - 1];
            int l2 = (c2 == 0) ? INT_MIN : nums2[c2 - 1];

            int r1 = (c1 == n1) ? INT_MAX : nums1[c1];
            int r2 = (c2 == n2) ? INT_MAX : nums2[c2];

            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2) * 1.0;
                }
            } else if (l1 > r2) {
                r = c1 - 1;
            } else {
                l = c1 + 1;
            }
        }

        return -1.0;
    }
};
// @lc code=end
