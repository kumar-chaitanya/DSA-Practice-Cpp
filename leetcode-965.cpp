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
  bool Util(TreeNode *root, int num) {
    if(root == NULL) return true;
    
    return (root->val == num) && Util(root->left, num) && Util(root->right, num);
  }
  
public:
  bool isUnivalTree(TreeNode *root) {
    if(root == NULL) return true;
    
    return Util(root, root->val);
  }
};