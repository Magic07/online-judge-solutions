/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:  
  bool findSubPath(ListNode* head, TreeNode* root){
    if(!head)
      return true;
    if(!root)
      return false;
    if(head->val==root->val){
      return findSubPath(head->next, root->left)||findSubPath(head->next, root->right);
    }
    return false;
  }
  bool isSubPath(ListNode* head, TreeNode* root) {
    if(!root)
      return false;
    return findSubPath(head, root)||isSubPath(head, root->left)||isSubPath(head, root->right);
  }
};