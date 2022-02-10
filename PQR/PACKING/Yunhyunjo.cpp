#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int c, n, k;
	cin >> c;


	while (c--) {
		cin >> n >> k;
		vector <pair <int, int>> v(n + 1);
		vector <string> s(n + 1);
		v.push_back({ 0,0 });
		s.push_back("");
		for (int i = 1; i <= n; i++) {
			cin >> s[i] >> v[i].first >> v[i].second;
		}

		vector <vector <int>> dp(n + 1, vector <int>(k + 1));
		vector <int> ss;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				if (v[i].first > j) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = max(dp[i - 1][j - v[i].first] + v[i].second, dp[i - 1][j]);
			}
		}
		int tmp = k;
		for (int i = n; i > 0; i--) {
			if (dp[i][tmp] != dp[i - 1][tmp]) {
				ss.push_back(i);
				tmp -= v[i].first;
			}
		}

		cout << dp[n][k] << " " << ss.size() << "\n";
		for (int i = 0; i < ss.size(); i++) {
			cout << s[ss[i]] << "\n";
		}
	}

	return 0;
}
