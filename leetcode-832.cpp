class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    int m,n;
    m = A.size();
    n = A[0].size();
    
    // Invert and Swap
    for(int i=0;i<m;i++) {
      int s = 0, e = n-1;
      while(s <= e) {
        if(s != e) {
          A[i][s] = !A[i][s];
          A[i][e] = !A[i][e];
        } else {
          A[i][s] = !A[i][s];
        }
        swap(A[i][s], A[i][e]);
        s++;
        e--;
      }
    }
    return A;
  }
};