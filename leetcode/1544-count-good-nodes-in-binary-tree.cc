/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root, int value){
        if(root==nullptr) return 0;
        int isGood(0);
        if(root->val>=value){
            isGood=1;
        }
        return goodNodes(root->left, max(value, root->val))+goodNodes(root->right, max(value, root->val))+isGood;
    }
    int goodNodes(TreeNode* root) {
        return goodNodes(root, INT_MIN);
    }
};