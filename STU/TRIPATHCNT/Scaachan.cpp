#include <bits/stdc++.h>

#define endl '\n'
#define rep(V,S,T) for(int V=S; V<T; ++V)

using namespace std;

typedef long long ll;

int N, tri[100][100];
ll memo[100][100][2]; // y, x, sum/cnt

ll pathcnt(int y, int x) {
	ll& cache_sum = memo[y][x][0];
	if (~cache_sum) return cache_sum;
	ll& cache_cnt = memo[y][x][1];

	if (y + 1 < N) {
		ll a = pathcnt(y + 1, x);
		ll b = pathcnt(y + 1, x + 1);
		if (a == b) {
			cache_cnt = memo[y + 1][x][1] + memo[y + 1][x + 1][1];
			return cache_sum = tri[y][x] + a;
		}
		else if (a < b) {
			cache_cnt = memo[y + 1][x + 1][1];
			return cache_sum = tri[y][x] + b;
		}
		else {
			cache_cnt = memo[y + 1][x][1];
			return cache_sum = tri[y][x] + a;
		}
	}

	cache_cnt = 1;
	return cache_sum = tri[y][x];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int TC; cin >> TC;
	while (TC--) {
		memset(memo, -1, sizeof(memo));
		cin >> N;
		rep(i, 0, N)
			rep(j, 0, i + 1)
				cin >> tri[i][j]; // end of input

		pathcnt(0, 0);
		cout << memo[0][0][1] << endl;
	}
}
