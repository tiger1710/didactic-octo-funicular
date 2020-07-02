#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
typedef pair<int, int> point;

class Tpath {
private:
	int V, E;
	vector<vector<point>> adj;
	
	
	void input(void) {
		cin >> V >> E;
		adj = vector<vector<point>>(V);
		while (E--) {
			int u, v, d; cin >> u >> v >> d;
			adj[u].push_back(make_pair(v, d));
			adj[v].push_back(make_pair(u, d));
		}
	}
	void calc(void) {
		
	}
	void output(void) {
		
	}
public:
	void solve(void) {
		input();
		calc();
		output();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int C; cin >> C;
	Tpath t;
	while (C--)
		t.solve();
	
	return 0;
}