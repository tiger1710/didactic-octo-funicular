#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;

class Hanoi {
private:
	const int MAX_DISCS = 12;
	int N, ans, state, end;
	vector<int> c;
	
	int sgn(const int& x) { return x ? (0 < x ? 1 : -1) : 0; }
	int incr(const int& x) { return 0 < x ? x + 1 : x - 1; }
	int get(const int& state, const int& index) { return (state >> (index << 1)) & 3; }
	int set(const int& state, const int& index, const int& value) {
		return (state & ~(3 << (index << 1))) | (value << (index << 1));
	}
	
	int bidir(const int& discs, const int& begin) {
		if (begin == end) return 0;
		c = vector<int>(1 << (MAX_DISCS << 1), 0);
		queue<int> q;
		q.push(begin); c[begin] = 1;
		q.push(end); c[end] = -1;
		
		
		while (not q.empty()) {
			int here = q.front();
			q.pop();
			
			int top[4] = { -1, -1, -1, -1 };
			for (int i = discs - 1; i >= 0; i--)
				top[get(here, i)] = i;
			
			for (int i = 0; i < 4; i++)
				if (top[i] not_eq -1)
					for (int k = 0; k < 4; k++)
						if (i not_eq k and (top[k] == -1 || top[k] > top[i])) {
							int there = set(here, top[i], k);
							if (not c[there]) {
								c[there] = incr(c[here]);
								q.push(there);
							}
							else if (sgn(c[there]) not_eq sgn(c[here]))
								return abs(c[there]) + abs(c[here]) - 1;
						}
		}
		
		return -1;
	}
	
	void input(void) {
		cin >> N;
		state = 0; end = (1 << (N << 1)) - 1;
		for (int i = 0; i < 4; i++) {
			int k; cin >> k;
			while (k--) {
				int disk; cin >> disk;
				state = set(state, disk - 1, i);
			}
		}
	}
	void calc(void) {
		ans = bidir(N, state);
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
	Hanoi h;
	while (C--)
		h.solve();
	
	return 0;
}