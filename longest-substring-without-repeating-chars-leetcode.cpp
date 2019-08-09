#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int num = 0, temp = 0;
    if(s.empty()) num = 0;
    
    unordered_map<char, bool> m;
    
    int i = 0, j = 0, n = s.size();
    
    while(j < n) {
      if(m.find(s[j]) != m.end()) {
        temp = j-i;
        num = max(num, temp);

        do {
         m.erase(s[i]);
        } while(i < j && s[i++] != s[j]);
        
       }

      m[s[j]] = true;
      j++;
    }
    
    num = max(num, j-i);
    return num;
  }
};

int main() {
  Solution s;
  cout << s.lengthOfLongestSubstring("abcabcdb") << endl;
  return 0;
}
