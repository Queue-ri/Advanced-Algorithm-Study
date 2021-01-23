#include <bits/stdc++.h>

#define endl '\n'
#define rep(V,S,T) for(int V=S; V<T; ++V)

using namespace std;

int seq[500], lis[500];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int TC; cin >> TC;
	while (TC--) {
		int N, ans = 0; cin >> N;
		rep(i, 0, N) cin >> seq[i]; // end of input

		int idx = 1;
		lis[0] = seq[0];
		rep(i, 1, N) {
			if (lis[idx-1] < seq[i])
				lis[idx++] = seq[i];
			else { // binary search lower bound
				int low = lower_bound(lis, lis+idx, seq[i]) - lis;
				lis[low] = seq[i];
			}
		}
		cout << idx << endl;
	}
}
