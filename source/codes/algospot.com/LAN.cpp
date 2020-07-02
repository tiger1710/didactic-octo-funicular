#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
using namespace std;
typedef pair<int, int> point;

class DisjointSet {
private:
	vector<int> parent, rank;
public:
	DisjointSet(const int& n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	int find(const int& u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	void merge(const int& u, const int& v) {
		int pu = find(u), pv = find(v);
		if (pu == pv) return;
		
		if (rank[pu] > rank[pv]) swap(pu, pv);
		parent[pu] = pv;
		if (rank[pu] == rank[pv]) rank[pv]++;
	}
};

class Kruskal {
private:
	vector<vector<pair<int, double>>> adj;
	vector<point> selected;
	int V;
	double ret;
public:
	Kruskal(const vector<vector<pair<int, double>>>& adj, const int& V) : adj(adj), V(V) { }
	
	//MST의 간선 목록 -> selected, 가중치의 합 반환
	double kruskal(void) {
		ret = 0.0;
		selected.clear();
		vector<pair<double, point>> edges;//(가중치, 정점1, 정점2)
		for (int u = 0; u < V; u++)
			for (const pair<int, double>& p : adj[u]) {
				double cost = p.second;
				edges.push_back(make_pair(cost, make_pair(u, p.first)));
			}
		sort(edges.begin(), edges.end());
		
		DisjointSet sets(V);
		for (const pair<double, point>& edge : edges) {
			double cost = edge.first;
			int u = edge.second.first, v = edge.second.second;
			if (sets.find(u) == sets.find(v)) continue;
			sets.merge(u, v);
			selected.push_back(make_pair(u, v));
			ret += cost;
		}
		return ret;
	}
};

class LAN {
private:
	const double INF = 1e9;
	int N, M;
	double ans;
	vector<point> pos;
	vector<vector<pair<int, double>>> adj;
	
	double between(const point& a, const point& b) {
		return sqrt((a.first - b.first) * (a.first - b.first) +
					(a.second - b.second) * (a.second - b.second));
	}
	
	void makeGraph(void) {
		for (int i = 0; i < N; i++)
			for (int k = i + 1; k < N; k++) {
				double dist = between(pos[i], pos[k]);
				adj[i].push_back(make_pair(k, dist));
				adj[k].push_back(make_pair(i, dist));
			}
	}
	
	void input(void) {
		cin >> N >> M;
		pos = vector<point>(N);
		adj = vector<vector<pair<int, double>>>(N);
		for (point& p : pos) cin >> p.second;
		for (point& p : pos) cin >> p.first;
		makeGraph();
		while (M--) {
			int u, v; cin >> u >> v;
			adj[u].push_back(make_pair(v, 0.0));
			adj[v].push_back(make_pair(u, 0.0));
		}
		
		/*for (const vector<double>& r : adj) {
			for (const double& c : r) {
				cout << c << ' ';
			}
			cout << endl;
		}*/
	}
	void calc(void) {
		Kruskal k(adj, N);
		ans = k.kruskal();
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
	
	(cout << fixed).precision(8);
	int C; cin >> C;
	
	LAN lan;
	while (C--)
		lan.solve();
	
	return 0;
}