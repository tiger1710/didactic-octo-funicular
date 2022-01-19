#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
typedef pair<int, int> point;

class Drunken {
private:
	const int INF = 987654321;
	int V, E;
	int T;
	vector<int> delay;
	vector<vector<int>> adj, W;
	
	void input(void) {
		cin >> V >> E;
		delay = vector<int>(V);
		W = adj = vector<vector<int>>(V, vector<int>(V, INF));
		for (int& i : delay) cin >> i;
		while (E--) {
			int A, B, C; cin >> A >> B >> C;
			W[A - 1][B - 1] = W[B - 1][A - 1] = adj[A - 1][B - 1] = adj[B - 1][A - 1] = C;
		}
	}
	void calc(void) {
		vector<point> order;
		for (int i = 0; i < V; i++)
			order.push_back(make_pair(delay[i], i));
		sort(order.begin(), order.end());
		
		for (int i = 0; i < V; i++)
			W[i][i] = 0;
		
		for (int w = 0; w < V; w++) {
			int p = order[w].second;
			for (int u = 0; u < V; u++)
				for (int v = 0; v < V; v++) {
					adj[u][v] = min(adj[u][v], adj[u][p] + adj[p][v]);
					W[u][v] = min(W[u][v], adj[u][p] + delay[p] + adj[p][v]);
				}
		}
	}
	void output(void) {
		cin >> T;
		while (T--) {
			int A, B; cin >> A >> B;
			cout << W[A - 1][B - 1] << endl;
		}
	}
public:
	void solve(void) {
		input();
		calc();
		output();
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	Drunken d;
	d.solve();

	
	return 0;
}