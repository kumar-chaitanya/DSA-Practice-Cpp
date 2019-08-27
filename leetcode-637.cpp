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
  vector<double> averageOfLevels(TreeNode* root) {
    
    vector<double> ans;
    queue<TreeNode *> q;
    TreeNode *temp;
    double sum;
    int n;
    
    q.push(root);
    
    while(!q.empty()) {
      n = q.size();
      sum = 0;
      
      for(int i=0;i<n;i++) {
        temp = q.front();
        q.pop();
        
        sum += temp->val;
        
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
      }
      
      ans.push_back(sum/n);
    }
    
    return ans;
    
  }
};