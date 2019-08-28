class Solution {
public:
  bool divisorGame(int N) {
    int a[N+1] = {0};
    a[1] = 0;
    
    for(int i=2;i<=N;i++) {
      for(int j=1;j<i;j++) {
        // Find divisors of i
        if(i%j == 0) {
          // Check if there is any possible factor which leads to winning of Alice
          a[i] = !a[i-j] || a[i];
        }
      }
    }
    
    return a[N];
  }
};