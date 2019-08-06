/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Node {
public:
  int x;
  int y;
  int val;

  Node(int x, int y, int val) {
    this->x = x;
    this->y = y;
    this->val = val;
  }
};

// When making custom comparator remember if compare(a, b) is true then compare(b,a) should be false,
// else will get an heap buffer runtime error.
class Compare {
public:
  bool operator()(Node a, Node b) {
    if(a.y > b.y) return true;
    else if (a.y < b.y) return false;
    else return (a.val < b.val);
  }
};

class Solution {
private:
  void solution(unordered_map<int, vector<Node>> &lookup, TreeNode *root, int &minD, int &maxD, int x, int y) {
    if(root == NULL) return;

    Node obj(x,y,root->val);

    if(lookup.find(x) != lookup.end())
      lookup[x].push_back(obj);
    else
      lookup[x] = vector<Node>(1, obj);

    if(x < minD) minD = x;
    if(x > maxD) maxD = x;

    if(root->left)
      solution(lookup, root->left, minD, maxD, x-1, y-1);
    if(root->right)
      solution(lookup, root->right, minD, maxD, x+1, y-1);

    return;
  }
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    int minD, maxD;
    minD = INT_MAX;
    maxD = INT_MIN;
    
    unordered_map<int, vector<Node>> lookup;

    solution(lookup, root, minD, maxD, 0, 0);

    Compare myCompare;
    vector<vector<int>> ans(maxD-minD+1);
    int x = 0;

    for(int i=minD;i<=maxD;i++) {
      auto it = lookup[i];
      int n = it.size();
      ans[x] = vector<int>(n);

      sort(it.begin(),it.end(),myCompare);

      for(int j=0;j<n;j++) {
        ans[x][j] = it[j].val;
      }
      x++;
    }
    return ans;
  }
};