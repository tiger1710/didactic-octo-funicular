#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

class Promises {
private:
	const int INF = 987654321;
	int V, M, N, ans;
	vector<vector<int>> adj;
	
	void floyd(void) {
		for (int i = 0; i < V; i++) adj[i][i] = 0;
		for (int w = 0; w < V; w++)
			for (int i = 0; i < V; i++)
				for (int k = 0; k < V; k++)
					adj[i][k] = min(adj[i][k], adj[i][w] + adj[w][k]);
	}
	bool update(const int& a, const int& b, const int& c) {
		if (adj[a][b] <= c) return false;
		for (int u = 0; u < V; u++)
			for (int v = 0; v < V; v++)
				adj[u][v] = min(adj[u][v],
								min(adj[u][a] + c + adj[b][v],
									adj[u][b] + c + adj[a][v]));
		return true;
	}
	
	void input(void) {
		cin >> V >> M >> N;
		adj = vector<vector<int>>(V, vector<int>(V, INF));
		while (M--) {
			int a, b, c; cin >> a >> b >> c;
			adj[a][b] = adj[b][a] = min(adj[a][b], c);
		}
	}
	void calc(void) {
		floyd();
		ans = 0;
		while (N--) {
			int a, b, c; cin >> a >> b >> c;
			if (not update(a, b, c)) ans++;
		}
	}
	void output(void) {
		cout << ans << endl;
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
	
	int C; cin >> C;
	Promises p;
	while (C--)
		p.solve();
	
	return 0;
}