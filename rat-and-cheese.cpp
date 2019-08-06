#include<iostream>
using namespace std;

void printPath(int path[][100], int n, int m) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << path[i][j] << " ";
    }
    cout << endl;
  }
  return;
}

bool findPath(char maze[][100], int path[][100], int i, int j, int n, int m) {
//   cout << i << " " << j << endl;
  if(maze[i][j]=='X') {
    return false;
  }
  
  if(i==n-1 && j==m-1) {
    path[i][j] = 1;
    printPath(path,n,m);
    return true;
  }

  if(i<0 || i>n-1 || j<0 || j>m-1) {
    return false;
  }

  path[i][j] = 1;

  bool left, right, top, down;
  left = right = top = down = false;
  if(!path[i][j+1])
    right = findPath(maze,path,i,j+1,n,m);

  if(!right && !path[i+1][j]) down = findPath(maze,path,i+1,j,n,m);

  if(!right && !down && !path[i][j-1]) left = findPath(maze,path,i,j-1,n,m);

  if(!right && !down && !left && !path[i-1][j]) top = findPath(maze,path,i-1,j,n,m);
  
  if(left || right || top || down) {
    return true;
  } else {
    path[i][j] = 0;
    return false;
  }
}

int main(){
  int n,m;
  char maze[100][100];
  int path[100][100] = {0};

  cin >> n >> m;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        cin >> maze[i][j];
    }
  }

  bool ans = findPath(maze,path,0,0,n,m);
  if(!ans) cout << "NO PATH FOUND" << endl;

  return 0;
}