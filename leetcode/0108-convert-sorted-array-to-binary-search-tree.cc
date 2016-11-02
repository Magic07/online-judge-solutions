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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.size() == 0) {
      return nullptr;
    }
    return sortedArrayToBST(nums, 0, nums.size() - 1);
  }
  TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
    if (start == end) {
      TreeNode* node = new TreeNode(nums[start]);
      return node;
    } else {
      int m(start + (end - start + 1) / 2);
      TreeNode* node = new TreeNode(nums[m]);
      if (start <= m - 1)
        node->left = sortedArrayToBST(nums, start, m - 1);
      if (m + 1 <= end)
        node->right = sortedArrayToBST(nums, m + 1, end);
      return node;
    }
  }
};