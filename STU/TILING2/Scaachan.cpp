#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

ll N;
const ll P = 1e9 + 7;
ll memo[102]; // 102 'cause it's checking the memo before the base case

ll tiling(int k) {
	ll& cache = memo[k];
	if (cache) return cache;
	if (k == N) return 1;
	if (k > N) return 0;

	return cache = (tiling(k + 1) + tiling(k + 2)) % P;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int TC; cin >> TC;
	while (TC--) {
		memset(memo, 0, sizeof(memo));
		cin >> N;
		cout << tiling(0) << endl;
	}
}
