#include <bits/stdc++.h>

#define endl '\n'
#define rep(V,S,T) for(int V=S; V<T; ++V)

using namespace std;

int N, fence[20000];

int divnq(int l, int r) {
	if (l == r) return fence[l];

	int m = (l + r) >> 1;
	int ans = max(divnq(l, m), divnq(m + 1, r)); // cmp l,r

	int low = m, high = m + 1;
	int minh = min(fence[low], fence[high]);
	ans = max(ans, minh << 1); // cmp max(l,r), low2high
	while (low > l || high < r) {
		if (high < r && (low == l || fence[low-1] < fence[high+1])) {
			++high;
			minh = min(minh, fence[high]);
		}
		else {
			--low;
			minh = min(minh, fence[low]);
		}
		ans = max(ans, minh * (high - low + 1));
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int TC; cin >> TC;
	while (TC--) {
		cin >> N;
		rep(i,0,N) cin >> fence[i];
		cout << divnq(0, N-1) << endl;
	}
}
