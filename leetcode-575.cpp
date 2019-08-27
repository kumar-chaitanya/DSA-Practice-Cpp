class Solution {
public:
  int distributeCandies(vector<int>& candies) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    unordered_map<int, bool> m;
    
    int n = candies.size();
    int total = n / 2, i = 0, count = 0;
    
    while(count < total && i < n) {
      if(m.find(candies[i]) == m.end()) {
        m[candies[i]] = true;
        count++;
      }
      i++;
    }
    
    return count;
  }
};