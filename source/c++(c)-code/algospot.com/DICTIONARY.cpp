#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define endl '\n'
using namespace std;

class Dictionary {
private:
	const int ALPHABETS = 26;
	int N;
	vector<vector<bool>> adj;
	vector<bool> visited;
	vector<string> words;
	vector<int> order, ans;
	const string error = "INVALID HYPOTHESIS";
	
	void dfs(const int& here) {
		visited[here] = true;
		for (int there = 0; there < ALPHABETS; there++)
			if (adj[here][there] and not visited[there])
				dfs(there);
		order.push_back(here);
	}
	vector<int> topologicalSort(void) {
		for (int i = 0; i < ALPHABETS; i++)
			if (not visited[i])
				dfs(i);
		reverse(order.begin(), order.end());
		for (int i = 0; i < order.size(); i++) {
			for (int k = 0 ; k < i; k++) {
				if (adj[order[i]][order[k]])
					return vector<int>();
			}
		}
			
		return order;
	}
	
	void input(void) {
		cin >> N;
		adj = vector<vector<bool>>(ALPHABETS, vector<bool>(ALPHABETS, false));
		visited = vector<bool>(ALPHABETS, false);
		for (int i = 0; i < N; i++) {
			string str; cin >> str;
			words.push_back(str);
		}
		for (int i = 0, k = 1; k < words.size(); i++, k++) {
			int len = min(words[i].length(), words[k].length());
			for (int l = 0; l < len; l++) {
				if (words[i][l] not_eq words[k][l]) {
					int u = words[i][l] - 'a';
					int v = words[k][l] - 'a';
					adj[u][v] = true;
					break;
				}
			}
		}
	}
	void calc(void) {
		ans = topologicalSort();
	}
	void output(void) {
		for (const int& i : ans)
			cout << static_cast<char>('a' + i);
		if (ans.empty()) cout << error;
		cout << endl;
		words.clear();
		order.clear();
		ans.clear();
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
	Dictionary dictionary;
	while (C--)
		dictionary.solve();
	
	return 0;
}
