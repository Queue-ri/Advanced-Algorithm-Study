#include <bits/stdc++.h>

#define endl '\n'
#define rep(V,S,T) for(int V=S; V<T; ++V)

using namespace std;

int N, M, K, memo[201][101]; // combination(n+m, n)
const int MAX = 1e9+1;

int nCr(int n, int r) {
	int &cache = memo[n][r];
	if (r == 0 || n == r) return cache = 1;
	if (cache) return cache;
	return cache = min(MAX, nCr(n - 1, r) + nCr(n - 1, r - 1));
}

string getstr(int n, int m) {
	if (n == 0) return string(m, 'o');
	if (K <= memo[n + m - 1][n - 1]) return '-' + getstr(n - 1, m);
	K -= memo[n + m - 1][n - 1];
	return 'o' + getstr(n, m - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	rep(r, 0, 101)
		rep(n, r, 201)
			nCr(n, r);

	int TC; cin >> TC;
	while (TC--) {
		cin >> N >> M >> K; // end of input
		cout << getstr(N, M) << endl;
	}
}
