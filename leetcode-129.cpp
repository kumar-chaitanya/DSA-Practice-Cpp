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
  void sumNumbersUtil(TreeNode *root, int &num, vector<int> &v) {
    if(root == NULL) return;
    
    if(!root->left && !root->right) {
      v.push_back(root->val);
      int n = v.size(), temp = 0;
      for(int j = 0; j < n; j++) {
        temp += v[j]*pow(10, n-j-1);
      }
      num += temp;
      v.pop_back();
      return;
    }
    
    v.push_back(root->val);
    
    sumNumbersUtil(root->left, num, v);
    sumNumbersUtil(root->right, num, v);
    
    v.pop_back();
    return;
  }
  
public:
  int sumNumbers(TreeNode *root) {
    if(root == NULL) return 0;
    vector<int> v;
    int num = 0;
    
    sumNumbersUtil(root, num, v);
    
    return num;
  }
};