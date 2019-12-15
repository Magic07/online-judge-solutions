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
    int getDecimalValue(ListNode* head) {
      stack<int> digitals;
      while(head){
        digitals.push(head->val);
        head=head->next;
      }
      int base(1);
      int decimal(0);
      while(!digitals.empty()){
        if(digitals.top()==1){
          decimal+=base;
        }
        base*=2;
        digitals.pop();
      }
      return decimal;
    }
};