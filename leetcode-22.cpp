class Solution {
  void Util(vector<string> &ans, string op, int o, int c, int n) {
    if(op.size() == 2*n) {
      ans.push_back(op);
      return;
    }
    
    if(o > 0) {
      op.push_back('(');
      Util(ans, op, o-1, c, n);
      op.pop_back();
    }
    
    if(c > o) {
      op.push_back(')');
      Util(ans, op, o, c-1, n);
    }
    
    return;
  }
public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string op;
    
    Util(ans, op, n, n, n);
    
    return ans;
  }
};