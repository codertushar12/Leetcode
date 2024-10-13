/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#define addTwoNumbers add_two_numbers

typedef ListNode Node;

class Solution {
  public:
    /**
     * T = O(max(N1, N2))
     * S = O(max(N1, N2))
     * 
     * N1 = size of list l1
     * N2 = size of list l2
     */
    Node* add_two_numbers(Node* l1, Node* l2) {
        Node* dead = new Node();
        Node* curr = dead;
        Node *head1 = l1, *head2 = l2;

        int sum = 0, carry = 0;

        while (head1 || head2) {
            sum = carry;

            if (head1) {
                sum = sum + (head1->val);
                head1 = head1->next;
            }

            if (head2) {
                sum = sum + (head2->val);
                head2 = head2->next;
            }

            curr->next = new Node(sum % 10);
            curr = curr->next;

            carry = sum / 10;
        }

        if (carry) {
            curr->next = new Node(carry);
        }

        return dead->next;
    }
};
// @lc code=end
