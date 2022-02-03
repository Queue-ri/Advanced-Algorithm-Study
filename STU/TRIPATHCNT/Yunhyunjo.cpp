#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int c, n;
	cin >> c;

	while (c--) {
		cin >> n;

		vector <vector <int>> v(n+1, vector <int> (n+1, 0));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				cin >> v[i][j];
			}
		}
		
		vector <vector <int>> dp(n+1, vector <int>(n+1, 0));
		vector <vector <int>> dp2(n + 1, vector <int>(n + 1, 0));
		dp[1][1] = v[1][1];
		dp2 [1][1] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				if (v[i][j] + dp[i - 1][j] > v[i][j] + dp[i - 1][j - 1]) {
					dp[i][j] = v[i][j] + dp[i - 1][j];
					dp2[i][j] = dp2[i - 1][j];
				}
				else if (v[i][j] + dp[i - 1][j] == v[i][j] + dp[i - 1][j - 1]) {
					dp[i][j] = v[i][j] + dp[i - 1][j];
					dp2[i][j] = dp2[i - 1][j] + dp2[i - 1][j - 1];
				}
				else {
					dp[i][j] = v[i][j] + dp[i - 1][j - 1];
					dp2[i][j] = dp2[i - 1][j - 1];
				}
			}
		}
		int max = 0, cnt = 0;

		for (int i = 1; i <= n; i++) {
			if (max < dp[n][i]) {
				max = dp[n][i];
				cnt = dp2[n][i];
			}
			else if (max == dp[n][i]) cnt += dp2[n][i];
		}

		cout << cnt << "\n";
	}
	

	return 0;
}