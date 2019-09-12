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
    stack<int> s1;
    stack<int> s2;
    stack<int> answer;
    ListNode* lt = l1;
    while (lt) {
      s1.push(lt->val);
      lt = lt->next;
    }
    lt = l2;
    while (lt) {
      s2.push(lt->val);
      lt = lt->next;
    }
    int carry = 0;
    while (!s1.empty() && !s2.empty()) {
      int currentDigit = s1.top() + s2.top() + carry;
      answer.push(currentDigit % 10);
      carry = currentDigit / 10;
      s1.pop();
      s2.pop();
    }
    while (!s1.empty()) {
      int currentDigit = s1.top() + carry;
      answer.push(currentDigit % 10);
      carry = currentDigit / 10;
      s1.pop();
    }
    while (!s2.empty()) {
      int currentDigit = s2.top() + carry;
      answer.push(currentDigit % 10);
      carry = currentDigit / 10;
      s2.pop();
    }
    if(carry!=0){
      answer.push(carry);
    }
    ListNode *result=new ListNode(answer.top());
    answer.pop();
    ListNode *last=result;
    while(!answer.empty()){
      ListNode *d=new ListNode(answer.top());
      last->next=d;
      last=d;
      answer.pop();
    }
    return result;
  }
};