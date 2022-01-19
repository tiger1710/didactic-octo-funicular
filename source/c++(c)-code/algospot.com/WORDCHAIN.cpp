#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define endl '\n';
using namespace std;

class WordChain {
private:
	static const short ALPHABETS = 26;
	string ret;
	int N, wordsCnt;
	vector<vector<int>> adj;
	vector<int> indegree, outdegree, eulerCircuit;
	vector<string> graph[ALPHABETS][ALPHABETS];
	
	void makeGraph(void) {
		for (int i = 0; i < ALPHABETS; i++)
			for (int k = 0; k < ALPHABETS; k++)
				graph[i][k].clear();
		wordsCnt = N;
		adj = vector<vector<int>>(ALPHABETS, vector<int>(ALPHABETS, 0));
		indegree = outdegree = vector<int>(ALPHABETS, 0);
		eulerCircuit.clear();
		
		for (int words = 0; words < N; words++) {
			string word; cin >> word;
			int u = word.front() - 'a';
			int v = word.back() - 'a';
			graph[u][v].push_back(word);
			adj[u][v]++;
			outdegree[u]++;
			indegree[v]++;
		}
	}
	void getEulerCircuit(const int& here) {
		for (int there = 0; there < ALPHABETS; there++) {
			while (adj[here][there] > 0) {
				adj[here][there]--;
				getEulerCircuit(there);
			}
		}
		eulerCircuit.push_back(here);
	}
	void getEulerTrailOrCircuit(void) {
		//getTrail
		for (int i = 0; i < ALPHABETS; i++) {
			if (outdegree[i] == indegree[i] + 1) {
				getEulerCircuit(i);
				return;
			}
		}
		
		//Or getCircuit
		for (int i = 0; i < ALPHABETS; i++) {
			if (outdegree[i]) {
				getEulerCircuit(i);
				return;
			}
		}
		
		//or nothing
		eulerCircuit.clear();
	}
	bool checkEuler(void) {
		int plus = 0, minus = 0;
		for (int i = 0; i < ALPHABETS; i++) {
			int delta = outdegree[i] - indegree[i];
			
			if (delta < -1 or 1 < delta) return false;
			
			switch (delta) {
				case 1:
					plus++;
					break;
				case -1:
					minus++;
					break;
				default:
					break;
			}
		}
		return (plus == 1 and minus == 1) or (plus == 0 and minus == 0);
	}
	
	
	void input(void) {
		cin >> N;
	}
	void calc(void) {
		makeGraph();
		
		if (not checkEuler()) {
			ret = "IMPOSSIBLE";
			return;
		}
		
		getEulerTrailOrCircuit();
		if (eulerCircuit.size() not_eq wordsCnt + 1) {
			ret = "IMPOSSIBLE";
			return;
		}
		
		reverse(eulerCircuit.begin(), eulerCircuit.end());
		ret = "";
		for (int i = 1; i < eulerCircuit.size(); i++) {
			int u = eulerCircuit[i - 1], v = eulerCircuit[i];
			if (ret.size()) ret += " ";
			ret += graph[u][v].back();
			graph[u][v].pop_back();
		}
	}
	void output(void) {
		cout << ret << endl;
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
	WordChain wc;
	while (C--)
		wc.solve();
	
	
	return 0;
}