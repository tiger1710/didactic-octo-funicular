#include <iostream>
#include <algorithm>
#include <vector>
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
		
		if (rank[u] > rank[v]) swap(pu, pv);
		parent[u] = v;
		if (rank[u] == rank[v]) rank[v]++;
	}
};

int main(void) {
	
	
	return 0;
}