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
  TreeNode* last=nullptr, *violation1=nullptr, *violation2=nullptr;
  void recoverTree(TreeNode* root) {
    traversalTree(root);
  }
  void traversalTree(TreeNode* root){
    TreeNode* current=root;
    while(current){
      if(current->left){
        TreeNode* pre=getMax(current);
        if(pre->right==nullptr){
          pre->right=current;
          current=current->left;
          continue;
        } else {
          //assert(pre->right==current);
          pre->right=nullptr;
          check(current);
          current=current->right;
        }
      } else {
        check(current);
        current=current->right;
      }
    }
    //assert(violation1!=nullptr);
    //assert(violation2!=nullptr);
    int temp=violation1->val;
    violation1->val=violation2->val;
    violation2->val=temp;
  }
  TreeNode* getMax(TreeNode* root){
    TreeNode* current=root->left;
    while(current->right&&current->right!=root){
      current=current->right;
    }
    return current;
  }
  void check(TreeNode* node){
    if(last&&node->val<last->val){
      if(violation1==nullptr){
        violation1=last;
      }
      violation2=node;
    }
    last=node;
  }
};