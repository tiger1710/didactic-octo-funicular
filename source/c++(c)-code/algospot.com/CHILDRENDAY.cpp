#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
//#define endl '\n'
using namespace std;

class ChildrenDay {
private:
	string D, ans;
	int N, M, MOD;
	
	int append(const int& here, const int& edge) {
		int there = here * 10 + edge;
		if (there >= MOD) return MOD + there % MOD;
		return there % MOD;
	}
	
	string gifts(void) {
		sort(D.begin(), D.end());
		
		vector<int> parent(N << 1, -1), choice(N << 1, -1);
		queue<int> q;
		parent[0] = 0;
		q.push(0);
		
		while (not q.empty()) {
			int here = q.front(); q.pop();
			for (const char& dight : D) {
				int there = append(here, dight - '0');
				if (parent[there] == -1) {
					parent[there] = here;
					choice[there] = dight - '0';
					q.push(there);
				}
			}
		}
		
		if (parent[N + M] == -1) return "IMPOSSIBLE";
		
		string ret;
		int here = N + M;
		while (parent[here] not_eq here) {
			ret += static_cast<char>('0' + choice[here]);
			here = parent[here];
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
	
	void input(void) {
		cin >> D >> N >> M;
		MOD = N;
	}
	void calc(void) {
		ans = gifts();
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
	
	int T; cin >> T;
	ChildrenDay cd;
	while (T--)
		cd.solve();
	
	
	return 0;
}