#include <bits/stdc++.h>

#define endl '\n';
#define rep(V,S,T) for(int V=S; V<T; ++V)

using namespace std;

bool f[10][10], avail[10];
int N, M;

int match(int s, int pair) {
	int ans = 0;

	rep(i, s+1, N) {
		if (f[s][i] && avail[i]) {
			if (pair >= N>>1) return 1; // base case
			avail[s] = avail[i] = false;

			rep(j, s+1, N)
				if (avail[j]) ans += match(j, pair+1);

			avail[s] = avail[i] = true;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int TC; cin >> TC;
	
	while (TC--) {
		memset(f, false, sizeof(f));
		memset(avail, true, sizeof(avail));

		cin >> N >> M;
		rep(i, 0, M) {
			int s1, s2; cin >> s1 >> s2;
			f[s1][s2] = f[s2][s1] = true;
		} // end of input

		cout << match(0, 1) << endl;
	}
}
