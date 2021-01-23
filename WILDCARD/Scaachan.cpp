#include <bits/stdc++.h>

#define endl '\n'
#define rep(V,S,T) for(int V=S; V<T; ++V)

using namespace std;

vector<string> v(50);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int TC; cin >> TC;
	while (TC--) {
		string _W, _R = ""; cin >> _W;

		rep(i, 0, _W.length()) { // wildcard to regex
			char& _wc = _W[i];
			if (_wc == '?') _R += '.';
			else if (_wc == '*') _R += ".*";
			else _R += _wc;
		}

		regex W (_R);
		int N; cin >> N;
		rep(i, 0, N) cin >> v[i]; // end of input

		vector<string> ans;
		for (auto s : v)
			if (regex_match(s, W)) ans.push_back(s);

		sort(ans.begin(), ans.end());
		for (auto s : ans) cout << s << endl;
	}
}
