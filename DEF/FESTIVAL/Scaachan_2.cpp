#include <bits/stdc++.h>

#define endl '\n'
#define rep(V,S,T) for(int V=S; V<T; ++V)

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int TC; cin >> TC;
	while (TC--) {
		int N, L; cin >> N >> L;
		vector<int> fee(1000), sum(1000);
		rep(i, 0, N) cin >> fee[i]; // end of input

		sum[0] = fee[0];
		rep(i, 1, N)
			sum[i] = sum[i - 1] + fee[i];

		double ans = 1e5;
		int part;
		rep(i, L, N+1) {
			ans = min(ans, sum[i - 1] / (double)i);
			rep(j, i, N) {
				part = sum[j] - sum[j - i];
				ans = min(ans, part / (double)i);
			}
		}
		cout << fixed;
		cout.precision(8);
		cout << ans << endl;
	}
}
