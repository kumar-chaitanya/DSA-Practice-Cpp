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
  void helper(TreeNode* root, vector<int> &ans, int y) {
    if(root == NULL) return;
    
    if(y > ans.size()) {
      ans.push_back(root->val);
    }
    
    helper(root->right, ans, y+1);
    helper(root->left, ans, y+1);
    
    return;
  }
public:
    vector<int> rightSideView(TreeNode* root) {
      vector<int> ans;
      helper(root, ans, 1);
      return ans;
    }
};