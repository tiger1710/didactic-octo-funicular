#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#define endl '\n';
using namespace std;
typedef pair<int, int> point;

class TimeTrip {
private:
	const int INF = 987654321;
	int G, W, ans[2];
	vector<vector<point>> adj;
	vector<vector<bool>> reachable;
	
	void isReachable(void) {
		for (int w = 0; w < G; w++)
			for (int u = 0; u < G; u++)
				for (int v = 0; v < G; v++)
					if (reachable[u][w] and reachable[w][v])
						reachable[u][v] = true;
	}
	
	void bellamnFordMin(void) {
		vector<int> upper(G, INF);
		upper[0] = 0;
		
		for (int it = 0; it < G - 1; it++)
			for (int here = 0; here < G; here++)
				for (const point& p : adj[here]) {
					int there = p.first;
					int cost = p.second;
					upper[there] = min(upper[there], upper[here] + cost);
				}
		
		for (int here = 0; here < G; here++)
			for (const point& p : adj[here]) {
				int there = p.first;
				int cost = p.second;
				if (upper[here] + cost < upper[there])
					if (reachable[0][here] and reachable[here][1]) {
						ans[0] = -INF;
						return;
					}
			}
		
		ans[0] = upper[1];
	}
	
	void bellamnFordMax(void) {
		vector<int> lower(G, INF);
		lower[0] = 0;
		
		for (int it = 0; it < G - 1; it++)
			for (int here = 0; here < G; here++)
				for (const point& p : adj[here]) {
					int there = p.first;
					int cost = -p.second;
					lower[there] = min(lower[there], lower[here] + cost);
				}
		
		for (int here = 0; here < G; here++)
			for (const point& p : adj[here]) {
				int there = p.first;
				int cost = -p.second;
				if (lower[here] + cost < lower[there])
					if (reachable[0][here] and reachable[here][1]) {
						ans[1] = -INF;
						return;
					}
			}
		
		ans[1] = lower[1];
	}
	void input(void) {
		cin >> G >> W;
		adj = vector<vector<point>>(G);
		reachable = vector<vector<bool>>(G, vector<bool>(G, false));
		while (W--) {
			int a, b, d; cin >> a >> b >> d;
			adj[a].push_back(make_pair(b, d));
			reachable[a][b] = true;
		}
	}
	void calc(void) {
		isReachable();
		if (not reachable[0][1]) return;
		bellamnFordMin();
		bellamnFordMax();
	}
	void output(void) {
		if (not reachable[0][1]) {
			cout << "UNREACHABLE" << endl;
			return;
		}
		
		if (ans[0] == -INF) cout << "INFINITY ";
		else cout << ans[0] << ' ';
		if (ans[1] == -INF) cout << "INFINITY";
		else cout << -ans[1];
		cout << endl;
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
	TimeTrip tt;
	while (C--)
		tt.solve();
	
	return 0;
}
