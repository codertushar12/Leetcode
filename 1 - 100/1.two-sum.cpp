/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#define twoSum two_sum

class Solution {
  public:
    /**
     * Single parse approach
     * T = O(N)
     * S = O(N)
     * 
     * N = size of nums array
     */
    vector<int> two_sum(vector<int>& nums, int target) {
        int n = nums.size();
        int complement;

        map<int, int> positions;

        vector<int> result(2, -1);

        for (int i = 0; i < n; i++) {
            complement = target - nums[i];

            if (positions.find(complement) != positions.end()) {
                result[0] = positions[complement];
                result[1] = i;

                return result;
            } else {
                positions[nums[i]] = i;
            }
        }

        return result;
    }
};
// @lc code=end
