#include <bits/stdc++.h>

#define rep(V,S,T) for(int V = S; V < T; ++V)
#define endl '\n'

using namespace std;

int fee[1000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int TC; cin >> TC;
	while (TC--) {
		int N, L, sum, min = 1e5, min_len;
		cin >> N >> L;
		rep(i, 0, N) cin >> fee[i];
		// end of input

		min_len = L;
		rep(len, L, N + 1) {
			sum = 0;
			rep(i, 0, len) sum += fee[i];
			if (sum * min_len < min * len) min = sum, min_len = len;

			rep(k, 0, N - len) {
				sum += fee[k + len] - fee[k];
				if (sum * min_len < min * len) min = sum, min_len = len;
			}
		}
		cout << fixed;
		cout.precision(8);
		cout << (double)min / min_len << endl;
	}
}
