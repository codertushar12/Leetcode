/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#define lengthOfLongestSubstring length_of_longest_substring

class Solution {
  public:
    /**
    * T = O(N)
    * S = O(N)
    * 
    * N = length of string 
    */
    int length_of_longest_substring(string s) {
        int ans = 0;
        int l = 0, r = 0;
        int n = s.length();

        map<char, int> frequency;

        while (r < n) {
            char x = s[r];
            frequency[x]++;

            while (l < r && frequency[x] > 1) {
                char y = s[l];
                frequency[y]--;

                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};
// @lc code=end
