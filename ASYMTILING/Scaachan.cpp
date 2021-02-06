#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

const ll P = 1e9 + 7;
ll memo[101];

ll tiling(int N) {
	if (N == 1 || N == 2) return N;
	ll& cache = memo[N];
	if (cache) return cache;

	return cache = (tiling(N - 1) + tiling(N - 2)) % P;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int TC; cin >> TC;
	while (TC--) {
		memset(memo, 0, sizeof(memo));
		int N; cin >> N; // end of input
		if (N == 1 || N == 2)
			cout << 0 << endl;
		else if (N & 1)
			cout << (tiling(N) - tiling(N>>1) + P) % P << endl;
		else {
			ll ans = tiling(N);
			ans = (ans - tiling(N>>1) + P) % P;
			ans = (ans - tiling((N>>1)-1) + P) % P;
			cout << ans << endl;
		}
	}
}
