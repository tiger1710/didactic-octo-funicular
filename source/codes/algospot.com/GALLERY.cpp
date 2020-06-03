#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define endl '\n'
using namespace std;

class Gallery {
private:
	vector<vector<int>> adj;
	vector<bool> visited;
	int installed;
	enum { UNWATCHED, WATCHED, INSTALLED };
	int G, H;
	
	int dfs(const int& here) {
		visited[here] = true;
		
		int children[3] = { 0, 0, 0 };
		
		for (const int& there : adj[here])
			if (not visited[there])
				children[dfs(there)]++;
		
		//자손 노드 중 감시되지 않는 노드가 있음
		if (children[UNWATCHED]) {
			installed++;
			return INSTALLED;
		}
		
		//자손 노드 중 카메라가 설치된 노드가 있음
		if (children[INSTALLED])
			return WATCHED;
			
		//leaf노드 or..
		return UNWATCHED;
	}
	void installCamera(void) {
		for (int u = 0; u < G; u++)
			if (not visited[u] and dfs(u) == UNWATCHED)
				installed++;//마지막 정점 카메라 설치시
	}
	
	void input(void) {
		cin >> G >> H;
		adj = vector<vector<int>>(G);
		visited = vector<bool>(G, false);
		installed = 0;
		
		while (H--) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	void calc(void) {
		installCamera();
	}
	void output(void) {
		cout << installed << endl;
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
	Gallery g;
	while (C--)
		g.solve();
	
	return 0;
}