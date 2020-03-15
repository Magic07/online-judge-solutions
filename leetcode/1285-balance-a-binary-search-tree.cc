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
    void getNumber(TreeNode* root, vector<int>& numbers){
      if(!root){
        return;
      }
      numbers.push_back(root->val);
      getNumber(root->left, numbers);
      getNumber(root->right, numbers);
    }
    TreeNode* buildBST(const vector<int>& numbers, int begin, int end){
      if(begin>end){
        return nullptr;
      }
      if(begin==end){
        return new TreeNode(numbers[begin]);
      }
      int midIndex=(end+begin)/2;
      int mid=numbers[midIndex];
      TreeNode* c=new TreeNode(mid);
      c->left=buildBST(numbers,begin, midIndex-1);
      c->right=buildBST(numbers, midIndex+1, end);
      return c;
    }
    TreeNode* balanceBST(TreeNode* root) {
      if(!root){
        return root;
      }
      vector<int> numbers;
      getNumber(root, numbers);
      sort(numbers.begin(), numbers.end());
      return buildBST(numbers, 0, numbers.size()-1);
    }
};