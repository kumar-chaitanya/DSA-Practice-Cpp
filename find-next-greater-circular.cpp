#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void findNextGreater(int a[], int n) {
	vector<int> res(n,-1);
	stack<int> s;
	s.push(0);

	int i;
	for(i=1;i<n;i++) {
		while(!s.empty() && (a[i] > a[s.top()])) {
			res[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}

	i = 0;

	while(!s.empty() && (i < s.top())) {
		if(a[i] > a[s.top()]) {
			res[s.top()] = a[i];
			s.pop();
		} else {
			i = (i+1)%n;
		}
	}
	
	for(i = 0;i<n;i++) {
		cout << res[i] << " ";
	}
	
	return;
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	findNextGreater(a,n);
	return 0;
}
