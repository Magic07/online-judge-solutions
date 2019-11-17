/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
  TreeNode* tree;
    void recovery(TreeNode* root){
      if(root->left){
        root->left->val=2*root->val+1;
        recovery(root->left);
      }
      if(root->right){
        root->right->val=2*root->val+2;
        recovery(root->right);
      }
    }
    FindElements(TreeNode* root) {
      tree=root;
      if(root!=nullptr){
        root->val=0;
        recovery(root);
      }
    }
    
    bool find(int target, TreeNode* root){
      if(target==root->val) return true;
      bool left(false), right(false);
      if(root->left){
        left=find(target, root->left);
      }
      if(root->right){
        right=find(target, root->right);
      }
      return left||right;
    }
    bool find(int target) {
      if(tree==nullptr) return false;
      return find(target, tree);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */