/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    long sum = getNumber(l1) + getNumber(l2);
    ListNode* header = new ListNode(sum % 10);
    ListNode* current = header;
    sum /= 10;
    while (sum != 0) {
      ListNode* ln = new ListNode(sum % 10);
      sum = sum / 10;
      current->next = ln;
      current = current->next;
    }
    return header;
  }

  long getNumber(ListNode* l) {
    long result = 0;
    long base = 1;
    while (l != nullptr) {
      result += (l->val) * base;
      base *= 10;
      l = l->next;
    }
    return result;
  }
};