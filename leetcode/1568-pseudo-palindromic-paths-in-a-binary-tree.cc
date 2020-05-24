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
    bool isPalindrome(const vector<int>& state){
        int odd(0);
        cout<<endl;
        for(int x: state){
            if(x%2){
                odd++;
            }
        }
        bool answer= odd>1?false:true;
        return answer;
    }
    int pseudoPalindromicPaths(TreeNode* root, vector<int>& state){
        state[root->val]++;
        if(root->left==nullptr&&root->right==nullptr){
            bool isP= isPalindrome(state)?1:0;
            state[root->val]--;
            return isP;
        }
        int answer(0);
        if(root->left){
            answer+=pseudoPalindromicPaths(root->left, state);
        }
        if(root->right){
            answer+=pseudoPalindromicPaths(root->right, state);
        }
        state[root->val]--;
        return answer;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> state(10);
        return pseudoPalindromicPaths(root, state);
    }
};