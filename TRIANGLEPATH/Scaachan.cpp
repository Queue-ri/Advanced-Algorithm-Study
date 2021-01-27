#include <bits/stdc++.h>

#define endl '\n'
#define rep(V,S,T) for(int V=S; V<T; ++V)

using namespace std;

int N, tri[100][100], memo[100][100];

int path(int y, int x) {
	int& cache = memo[y][x];
	if (cache) return cache;

	if (y + 1 < N)
		return cache = tri[y][x] + max(path(y + 1, x), path(y + 1, x + 1));
	
	return tri[y][x];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int TC; cin >> TC;
	while (TC--) {
		memset(memo, 0, sizeof(memo));
		cin >> N;
		rep(i, 0, N)
			rep(j, 0, i + 1)
				cin >> tri[i][j];

		cout << path(0, 0) << endl;
	}
}
