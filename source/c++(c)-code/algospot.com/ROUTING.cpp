#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>
#include <vector>
#define endl '\n'
using namespace std;
typedef pair<double, int> point;

class Dijkstra {
private:
	const double INF = numeric_limits<double>::max();
	//그래프의 인접리스트 (간선 가중치, 연결된 정점 번호)
	vector<vector<point>> adj;
	vector<double> dist;
	void dijkstra(void) {
		dist[0] = 1.0;
		priority_queue<point> pq;
		pq.push(make_pair(-1.0, 0));
  
		while (not pq.empty()) {
			const double cost = -pq.top().first;
			const int here = pq.top().second;
			pq.pop();
			if (dist[here] < cost) continue;
		
			for (const point& next : adj[here]) {
				const double nextCost = cost * next.first;
				const int there = next.second;
				if (nextCost < dist[there]) {
					dist[there] = nextCost;
					pq.push(make_pair(-nextCost, there));
				}
			}
		}
	}
public:
	Dijkstra(const vector<vector<point>>& adj) : adj(adj), dist(adj.size(), INF) { }
	double sp(void) {
		dijkstra();
		return dist[adj.size() - 1];
	}
};

class Routing {
private:
	int N, M;
	double ans;
	vector<vector<point>> adj;
	
	void input(void) {
		cin >> N >> M;
		adj = vector<vector<point>>(N);
		while (M--) {
			int a, b; double c; cin >> a >> b >> c;
			adj[a].push_back(point(c, b));
			adj[b].push_back(point(c, a));
		}
	}
	void calc(void) {
		ans = Dijkstra(adj).sp();
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
	(cout << fixed).precision(10);
	
	int C; cin >> C;
	Routing r;
	while (C--)
		r.solve();
	
	
	return 0;
}