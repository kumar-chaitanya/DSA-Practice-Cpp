class Solution {
public:
  int binaryGap(int N) {
    int c = 0, p = -1, i = 0;
    
    while(N != 0) {
      if(N&1) {
        if(p!=-1) c = max(c, i-p);
        p = i;
      }
      N = N>>1;
      i++;
    }
    return c;
  }
};