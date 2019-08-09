/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
  // Function to Convert string to int - Copied from stackoverflow :)
  int string2int(string s){
    stringstream ss;
    ss << s;
    int x;
    ss >> x;
    return x;
  }
public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    queue<TreeNode*> q;
    
    // Initializing an empty string
    string s("");
    
    if(root == NULL) return s;
    
    q.push(root);
    
    while(!q.empty()) {
      int n = q.size();
      TreeNode *t;
      for(int i = 0; i < n; i++) {
        t = q.front();
        q.pop();
        
        if(t != NULL) {
          s += to_string(t->val);
          
          if(t->left) q.push(t->left);
          else q.push(NULL);
          
          if(t->right) q.push(t->right);
          else q.push(NULL);
        }
        else {
         s += "X"; 
        }
        
        s += ",";
      }
    }
    
    // cout << s << endl;
    s.pop_back();
    return s;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string s) {
    if(s.empty()) return NULL;
    queue<TreeNode*> q;
    vector<string> v;

    int pos = 0, i = 0, n = 0;

    TreeNode *root = NULL;

    // Splitting the data and storing in a vector
    while(pos != -1) {
      pos = s.find(',', i);
      v.push_back(s.substr(i, pos - i));
      i = pos + 1;
    }

    // for(auto a : v) {
    //   cout << a << " ";
    // }

    root = new TreeNode(string2int(v[0]));
    q.push(root);

    i = 1;
    n = v.size();

    while(!q.empty()) {
      auto temp = q.front();

      if(i < n-1) {
        auto a = v[i];
        auto b = v[i+1];  
      
        if(a.compare("X") != 0) {
          TreeNode *l = new TreeNode(string2int(a));
          temp->left = l;
          q.push(l);
        }
        if(b.compare("X") != 0) {
          TreeNode *r = new TreeNode(string2int(b));
          temp->right = r;
          q.push(r);
        }

        q.pop();
        i += 2;
      }
    }


    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));