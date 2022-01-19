#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define endl '\n'
using namespace std;

class SortGame {
private:
	map<vector<int>, int> toSort;
	vector<int> perm;
	int N, ans;
	
	void preCalc(void) {
		vector<int> perm(N);
		for (int i = 0; i < N; i++)
			perm[i] = i;
		queue<vector<int>> q;
		q.push(perm);
		toSort[perm] = 0;
		
		while (not q.empty()) {
			vector<int> here = q.front();
			q.pop();
			int cost = toSort[here];
			
			for (int i = 0; i < N; i++)
				for (int k = i + 2; k <= N; k++) {
					reverse(here.begin() + i, here.begin() + k);
					if (toSort.find(here) == toSort.end()) {
						toSort[here] = cost + 1;
						q.push(here);
					}
					reverse(here.begin() + i, here.begin() + k);
				}
			
		}
	}
	
	void input(void) {
		cin >> N;
		perm = vector<int>(N);
		for (int& i : perm) cin >> i;
	}
	void calc(void) {
		preCalc();
		vector<int> fixed(N);
		for (int i = 0; i < N; i++) {
			int smaller = 0;
			for (int k = 0; k < N; k++)
				perm[k] < perm[i] ? smaller++ : 0;
			fixed[i] = smaller;
		}
		ans = toSort[fixed];
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
	SortGame sg;
	while (C--)
		sg.solve();
	
	return 0;
}