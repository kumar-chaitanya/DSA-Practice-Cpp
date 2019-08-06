#include<bits/stdc++.h>
#define MAX 1e6
using namespace std;

class Node {
public:
	int rail, plane;

	Node(int rail, int plane) {
		this->rail = rail;
		this->plane = plane;
	}
};

template <typename T>
class Graph {
private:
	map<T, list<pair<T, Node>>> m;

public:
	void addEdge(T u, T v, int rail, int plane) {
		Node n(rail, plane);
		m[u].push_back(make_pair(v, n));
		m[v].push_back(make_pair(u, n));

		return;
	}

	void printGraph() {
		for(auto node : m) {
			cout << node.first << " : ";
			for(auto p : node.second) {
				cout << "( " << p.first << ", " << p.second.rail << ", " << p.second.plane << " ) ";
			}
			cout << endl;
		}
	}

	void findMinTravelCost(T src) {
		// rc stands for rail cost or cost with no plane for the node
		map<T, int> rc;
		// pc stands for cost with 1 plane involved for the node
		map<T, int> pc;
		// ac stands for the actual min cost for the node

		for(auto n : m) {
			rc[n.first] = MAX;
			pc[n.first] = MAX;
		}

		// Set rail cost of src as 0 and keep plane cost as INT_MAX
		rc[src] = 0;

		set<pair<int, T>> s;
		s.insert(make_pair(0, src));

		while(!s.empty()) {
			pair<int, T> p = *(s.begin());
			T node = p.second;
      // cout << node << endl;
			s.erase(s.begin());

			for(auto c : m[node]) {
				int Rc, Pc, curcost, prevcost;
				// Calculate only rail or no plane cost for child
				Rc = rc[node] + c.second.rail;
				if(Rc < rc[c.first]) rc[c.first] = Rc;

				// Calculate one plane cost for child
				Pc = min(rc[node]+c.second.plane, pc[node]+c.second.rail);
				if(Pc < pc[c.first]) pc[c.first] = Pc;

				// Find least cost among both
				curcost = min(Rc, Pc);
				prevcost = min(rc[c.first], pc[c.first]);
        // cout << c.first << " " << curcost << " " << prevcost << endl;
				// Check if this child is present or not in the set
				auto f = s.find(make_pair(prevcost, c.first));
        if(curcost <= prevcost) {
          if(f != s.end())
          	s.erase(f);

          s.insert(make_pair(curcost, c.first));
        }
			}
		}

		for(auto n : rc) {
			cout << src << " to " << n.first << " = " << min(n.second, pc[n.first]) << endl;
		}
	}
};

int main() {
	Graph<char> g;
    int n;
    cin >> n;
    while(n--) {
        char u, v;
        int r, p;
        cin >> u >> v;
        cin >> r >> p;
        g.addEdge(u, v, r, p);
    }
	// g.printGraph();
	g.findMinTravelCost('a');
	return 0;
}

// Sample Test Cases
// First line is the number of edges n followed by n edges
// An Egde is represented by u, v which are src, dest respectively and r, p which are rail
// and plane cost for that edge

// 9
// a d 1 2
// a c 4 5
// a b 10 4
// d f 3 1
// f b 5 3
// b g 1 1
// b c 6 7
// c e 5 2
// e g 2 3