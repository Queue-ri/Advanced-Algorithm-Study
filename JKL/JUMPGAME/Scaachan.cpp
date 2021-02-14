#include <bits/stdc++.h>

#define endl '\n'
#define rep(V,S,T) for(int V=S; V<T; ++V)

using namespace std;

int N, game[100][100], memo[100][100][2]; // only cache for 0

int jump(int y, int x) {
	if (y >= N || x >= N) return 0;
	if (y == N - 1 && x == N - 1) return 1;

	int& dcache = memo[y][x][0];
	int& rcache = memo[y][x][1];

	int d = game[y][x];
	if (dcache) { 
		if (jump(y + d, x)) return 1;
		else dcache = 0;
	}
	if (rcache) {
		if (jump(y, x + d)) return 1;
		else rcache = 0;
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int TC; cin >> TC;
	while (TC--) {
		memset(memo, -1, sizeof(memo));
		cin >> N;
		rep(i, 0, N)
			rep(j, 0, N)
				cin >> game[i][j];

		cout << (jump(0, 0) ? "YES" : "NO") << endl;
	}
}
