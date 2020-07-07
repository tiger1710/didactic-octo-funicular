#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef pair<int, int> point;
//class DisjointSet {
//private:
//	vector<int> parent, rank;
//public:
//	DisjointSet(const int& n) : parent(n), rank(n, 1) {
//		for (int i = 0; i < n; i++)
//			parent[i] = i;
//	}
//	int find(const int& u) {
//		if (u == parent[u]) return u;
//		return parent[u] = find(parent[u]);
//	}
//	void merge(const int& u, const int& v) {
//		int pu = find(u), pv = find(v);
//		if (pu == pv) return;
//	
//		if (rank[pu] > rank[pv]) swap(pu, pv);
//		parent[pu] = pv;
//		if (rank[pu] == rank[pv]) rank[pv]++;
//	}
//};
class Tpath {
private:
	const int INF = 987654321;
	int V, E, ans;
	vector<vector<point>> adj;
	vector<int> weights;//��簣���� ����ġ ���. ����
	vector<pair<int, point>> edges;//(����ġ, (����1, ����2))
	vector<bool> visited;
	
	bool searchCondition(const point& p, const int& low, const int& high) {
		return not visited[p.first] and
			low <= p.second and  p.second <= high;
	}
	bool hasPath(const int& here, const int& low, const int& high) {
		visited[here] = true;
		if (here == V - 1) return true;
		for (const point& there : adj[here])
			if (searchCondition(there, low, high))
				if (hasPath(there.first, low, high))
					return true;
		return false;
	}
	//����ġ�� weights[low]�̻��� �������� �������� �������� �����ϴ�
	//�ʿ��� ����� �ּ� ����. ������ �� ���� ��� INF
	//�̺�Ž��
	//int minUpperBound(const int& low) {
	//	int lo = low - 1, hi = weights.size();
	//
	//	while (lo + 1 < hi) {
	//		const int mid = (lo + hi) >> 1;
	//
	//		visited = vector<bool>(V, false);
	//		if (hasPath(0, weights[low], weights[mid])) hi = mid;
	//		else lo = mid;
	//	}
	//
	//	if (hi == weights.size()) return INF;
	//	return weights[hi];
	//}
	//����ġ�� weights[low]�̻��� �������� �������� �������� �����ϴ�
	//�ʿ��� ����� �ּ� ����. ������ �� ���� ��� INF
	//int kruskalMinUpperBound(const int& low) {
	//	DisjointSet sets(V);
	//	//edges�� ���ĵǾ�����.
	//	for (const pair<int, point>& edge : edges) {
	//		if (edge.first < weights[low]) continue;
	//		sets.merge(edge.second.first, edge.second.second);
	//		if (sets.find(0) == sets.find(V - 1))
	//			return edge.first;
	//	}
	//	return INF;
	//}
	
	//�������� ���
	int scanning(void) {
		int lo = 0, hi = 0, ret = INF;
		while (lo < weights.size() and hi < weights.size()) {
			visited = vector<bool>(V, false);
			if (hasPath(0, weights[lo], weights[hi])) {
				ret = min(ret, weights[hi] - weights[lo]);
				lo++;
			}
			else hi++;
		}
		return ret;
	}
	
	void input(void) {
		cin >> V >> E;
		adj = vector<vector<point>>(V);
		weights.clear();
		while (E--) {
			int u, v, d; cin >> u >> v >> d;
			adj[u].push_back(make_pair(v, d));
			adj[v].push_back(make_pair(u, d));
			weights.push_back(d);
		}
	}
	void calc(void) {
		sort(weights.begin(), weights.end());
		ans = scanning();
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
	Tpath t;
	while (C--)
		t.solve();
	
	return 0;
}