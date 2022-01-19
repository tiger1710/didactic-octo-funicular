#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;
typedef pair<int, int> point;

class Dijkstra {
private:
	const int INF = numeric_limits<int>::max();
	//그래프의 인접리스트 (간선 가중치, 연결된 정점 번호)
	vector<vector<point>> adj;
	vector<int> dist, fireStation;
	void dijkstra(void) {
		priority_queue<point> pq;
		for (const int& start : fireStation) {
			dist[start] = 0;
			pq.push(make_pair(0, start));
		}
  
		while (not pq.empty()) {
			const int cost = -pq.top().first;
			const int here = pq.top().second;
			pq.pop();
			if (dist[here] < cost) continue;
		
			for (const point& next : adj[here]) {
				const int nextCost = cost + next.first;
				const int there = next.second;
				if (nextCost < dist[there]) {
					dist[there] = nextCost;
					pq.push(make_pair(-nextCost, there));
				}
			}
		}
	}
public:
	Dijkstra(const vector<vector<point>>& adj, const vector<int>& fireStation) : adj(adj), dist(adj.size(), INF), fireStation(fireStation) { }
	vector<int> sp(void) {
		dijkstra();
		return dist;
	}
};

class FireTrucks {
private:
	int V, E, n, m, ans;
	vector<vector<point>> adj;
	vector<int> fire, fireStation;
	
	void input(void) {
		cin >> V >> E >> n >> m;
		adj = vector<vector<point>>(V);
		while (E--) {
			int a, b, t; cin >> a >> b >> t;
			adj[a - 1].push_back(make_pair(t, b - 1));
			adj[b - 1].push_back(make_pair(t, a - 1));
		}
		while (n--) {
			int f; cin >> f;
			fire.push_back(f - 1);
		}
		while (m--) {
			int s; cin >> s;
			fireStation.push_back(s - 1);
		}
	}
	void calc(void) {
		vector<int> times = Dijkstra(adj, fireStation).sp();
		ans = 0;
		for (const int& f : fire)
			ans += times[f];
		fire.clear(); fireStation.clear();
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
	FireTrucks ft;
	while (C--)
		ft.solve();
	
	return 0;
}