class FindNode {
public:
  int d;
  bool present;
};

class Solution {
  void findAtDepth(vector<int> &ans, TreeNode* root, int d) {
    if(root == NULL) return;
    if(d < 0) return;
    if(d == 0) ans.push_back(root->val);
    
    findAtDepth(ans, root->left, d-1);
    findAtDepth(ans, root->right, d-1);
    
    return;
  }
  
  FindNode helper(vector<int> &ans, TreeNode* root, TreeNode* target, int k, int d) {
    FindNode f;    
    if(root == NULL) {
      f.d = d-1;
      f.present = false;
      return f;
    }
    
    if(root == target) {
      f.d = d;
      f.present = true;
      findAtDepth(ans, root, k);
      return f;
    }
    int diff;
    FindNode left = helper(ans, root->left, target, k, d+1);
    if(left.present) {
      // Find at depth k-d from right subtree
      diff = left.d - d;
      if(k-diff == 0) ans.push_back(root->val);
      else findAtDepth(ans, root->right, k-diff-1);
      
      return left;
    } else {
      FindNode right = helper(ans, root->right, target, k, d+1);
      // Find at depth k-d from left subtree
      if(right.present) {
        diff = right.d - d;
        if(k-diff == 0) ans.push_back(root->val);
        else findAtDepth(ans, root->left, k-diff-1);
      
        return right; 
      }
    }
    
    f.d = d;
    f.present = false;
    return f;
  }
  
public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> ans;
    FindNode f = helper(ans, root, target, k, 0);
    return ans;
  }
};