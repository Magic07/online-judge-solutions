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
  unordered_map<TreeNode*, pair<int,int>> dp;
  int answer;

  void longestZigZagFromMap(TreeNode* root){
    answer=max(answer, max(dp[root].first, dp[root].second));
    if(root->left){
      longestZigZagFromMap(root->left);
    }
    if(root->right){
      longestZigZagFromMap(root->right);
    }
  }
  int longestZigZag(TreeNode* root, bool left){
    if(left&&dp[root].first!=0){
      return dp[root].first;
    } else if(!left&&dp[root].second!=0){
      return dp[root].first;
    }
    if(left){
      if(root->left){
        int answer=longestZigZag(root->left, false)+1;
        dp[root].first=answer;
        return answer;
      } else {
        return 0;
      }
    } else {
      if(root->right){
        int answer=longestZigZag(root->right, true)+1;
        dp[root].second=answer;
        return answer;
      } else {
        return 0;
      }
    }
  }
  void longestZigZagInternal(TreeNode* root) {
    if(root==nullptr){
      return;
    }
    longestZigZag(root, true);
    longestZigZag(root, false);
    longestZigZagInternal(root->left);
    longestZigZagInternal(root->right);
  }
  int longestZigZag(TreeNode* root) {
    answer=0;
    longestZigZagInternal(root);
    longestZigZagFromMap(root);
    return answer;
  }
};