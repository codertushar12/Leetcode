/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#define longestPalindrome longest_palindrome

class Solution {
  public:
    /**
     * T = O(N^2)
     * S = O(1)
     * 
     * N = length of string
     */
    string longest_palindrome(string s) {
        int l = 0, r = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int palindrome_len = max(find_palindrome_len(s, i, i, n),
                                     find_palindrome_len(s, i, i + 1, n));

            if (palindrome_len > r - l + 1) {
                l = i - (palindrome_len - 1) / 2;
                r = i + (palindrome_len / 2);
            }
        }

        return s.substr(l, r - l + 1);
    }

    int find_palindrome_len(string s, int l, int r, int n) {
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }

        return r - l - 1;
    }
};
// @lc code=end
