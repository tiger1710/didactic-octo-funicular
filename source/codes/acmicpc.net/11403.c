#include <stdio.h>
#include <stdbool.h>

#define MAX 105

int G[MAX][MAX];
bool visited[MAX];
int N;

bool dfs(int cur, int target) {
	visited[cur] = true;
	if (G[cur][target]) {
		return true;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (G[cur][i] && !visited[i]) {
				if (dfs(i, target)) {
					return true;
				}
			}
		}
		return false;
	}
}

int main(void) {
	scanf("%d", &N);
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			int way;
			scanf("%d", &way);
			G[r][c] = way;
		}
	}

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (dfs(r, c)) {
				fputs("1 ", stdout);
			}
			else {
				fputs("0 ", stdout);
			}
			for (int i = 0; i < N; i++) {
				visited[i] = false;
			}
		}
		puts("");
	}

	return 0;
}
