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
    int sumEvenGrandparent(TreeNode* root, bool isParentEven, bool isGrandParentEven){
      int answer(0);
      if(root==nullptr)
        return answer;
      if(isGrandParentEven)
        answer+=root->val;
      bool isValEven=root->val%2?false:true;
      answer+=sumEvenGrandparent(root->left, isValEven, isParentEven)+sumEvenGrandparent(root->right, isValEven, isParentEven);
      return answer;
    }
    int sumEvenGrandparent(TreeNode* root) {
      return sumEvenGrandparent(root,false, false);
    }
};