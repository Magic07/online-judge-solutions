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
  unordered_map<TreeNode*, bool> bst;
  int maxSum;
  bool isBST(TreeNode* root){
    if(bst.find(root)!=bst.end()){
      return bst[root];
    }
    bool answer(true);
    if(root->left){
      if(root->left->val<root->val){
        if(!isBST(root->left)){
          answer=false;
        }
      } else {
        isBST(root->left);
        answer=false;
      }
    }
    if(root->right){
      if(root->right->val>root->val){
        if(!isBST(root->right)){
          answer=false;
        }
      } else {
        isBST(root->right);
        answer=false;
      }
    }
    bst[root]=answer;
    return answer;
  }
  int getSum(TreeNode* root){
    if(root==nullptr){
      return 0;
    }
    int result=getSum(root->left)+getSum(root->right)+root->val;
    maxSum=max(result, maxSum);
    return result;
  }
  int bstSum(TreeNode* root){
    if(root==nullptr){
      return 0;
    }
    if(bst[root]){
      return getSum(root);
    } else {
      return max(bstSum(root->left), bstSum(root->right));
    }
  }
  int maxSumBST(TreeNode* root) {
    maxSum=0;
    isBST(root);
    return max(bstSum(root),maxSum);
  }
};