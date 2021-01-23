#include <bits/stdc++.h>

#pragma comment(linker, "/STACK:16777216") // for Visual Studio

#define endl '\n'
#define rep(V,S,T) for(int V=S; V<T; ++V)

using namespace std;

int sz, sarr[10000], memo[10000];

inline int diff(int idx, int len) {
	rep(i, idx + 1, idx + len)
		if (sarr[i] != sarr[idx]) goto L2;
	return 1;
L2:
	int d = sarr[idx] - sarr[idx+1];
	rep(i, idx+2, idx+len)
		if (sarr[i - 1] - sarr[i] != d) goto L1;
	return (d == 1 || d == -1) ? 2 : 5;
L1:
	rep(i, idx+2, idx+len)
		if (sarr[i-2] != sarr[i]) return 10;
	return 4;
}

int split(int idx) {
	int& cache = memo[idx];
	if (cache) return cache;
	if (idx == sz) return 0; // done!

	cache = 0x7fffff00; // prevent arithmetic overflow
	rep(i, 3, 6) {
		if (idx + i > sz) continue;
		int t = diff(idx, i) + split(idx + i);
		if (t < cache) cache = t;
	}
	return cache;
}

int main() {
	char mybuffer[500001]; // for Visual Studio
	setvbuf(stdin, mybuffer, _IOFBF, sizeof(mybuffer)); // for Visual Studio
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int TC; cin >> TC;
	while (TC--) {
		memset(memo, 0, sizeof(memo));
		string s; cin >> s; // end of input
		sz = s.length();
		rep(i, 0, sz)
			sarr[i] = s[i] - 48;
		cout << split(0) << endl;
	}
}
