#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

constexpr int INF = numeric_limits<int>::max() >> 1;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N; cin >> N;
	
	vector<vector<int>> cost(N, vector<int>(N, INF));
	for (int i = 0; i < N; i++) {
		for (int k = 0, d; k < N; k++) {
			cin >> d;
			if (d) {
				cost[i][k] = 0;
			}
		}
	}

	for (int bypass = 0; bypass < N; bypass++) {
		for (int i = 0; i < N; i++) {
			for (int k = 0; k < N; k++) {
				cost[i][k] = min(cost[i][k], cost[i][bypass] + cost[bypass][k]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			cout << (cost[i][k] not_eq INF ? 1 : 0) << ' ';
		}
		cout << '\n';
	}

	return 0;
}
