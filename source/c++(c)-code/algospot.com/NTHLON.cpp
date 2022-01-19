#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> point;

class Dijkstra {
private:
	const int INF = 987654321;
	int V;
	vector<int> a, b;
	
	vector<vector<point>> adj;
	const int START = 401;
	
	int vertex(const int& delta) {
		return delta + 200;
	}
	vector<int> dijkstra(void) {
		vector<int> dist(V, INF);
		dist[START] = 0;
		priority_queue<point> pq;
		pq.push(make_pair(0, START));
		
		while (not pq.empty()) {
			int cost = -pq.top().first;
			int here = pq.top().second;
			pq.pop();
			if (dist[here] < cost) continue;
			
			for (const point& p : adj[here]) {
				int there = p.second;	
				int nextDist = cost + p.first;
				
				if (nextDist < dist[there]) {
					dist[there] = nextDist;
					pq.push(make_pair(-nextDist, there));
				}
			}
		}
		return dist;
	}
public:
	Dijkstra(const vector<int>& a, const vector<int>& b) : a(a), b(b) { }
	int time(void) {
		V = 402;
		adj = vector<vector<point>>(410);
		for (int i = 0; i < a.size(); i++) {
			int delta = a[i] - b[i];
			adj[START].push_back(make_pair(a[i], vertex(delta)));
		}
		
		for (int delta = -200; delta <= 200; delta++) {
			for (int i = 0; i < a.size(); i++) {
				int next = delta + a[i] - b[i];
				if (abs(next) > 200) continue;
				adj[vertex(delta)].push_back(make_pair(a[i], vertex(next)));
			}
		}
		
		vector<int> shortest = dijkstra();
		int ret = shortest[vertex(0)];
		if (ret == INF) return -1;
		return ret;
	}
};

class Nthlon {
private:
	vector<int> a, b;
	int ans;
	
	void input(void) {
		int M; cin >> M;
		while (M--) {
			int ta, tb; cin >> ta >> tb;
			a.push_back(ta);
			b.push_back(tb);
		}
	}
	void calc(void) {
		ans = Dijkstra(a, b).time();
		a.clear(); b.clear();
	}
	void output(void) {
		if (ans not_eq -1) cout << ans << endl;
		else cout << "IMPOSSIBLE" << endl;
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
	Nthlon n;
	while (C--)
		n.solve();
	
	return 0;
}