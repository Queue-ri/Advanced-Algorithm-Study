#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int N, M;
double memo[1000][2000];

double up(int day, int h) {
	if (day >= M) return h >= N ? 1.0 : 0.0;
	double& cache = memo[day][h];
	if (cache != -1.0) return cache;

	return cache = 0.25 * up(day + 1, h + 1) + 0.75 * up(day + 1, h + 2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int TC; cin >> TC;
	cout << fixed;
	cout.precision(8);
	while (TC--) {
		fill(memo[0], memo[0] + 1000 * 2000, -1.0);
		cin >> N >> M;
		cout << ((N > M << 1) ? 0.0 : up(0, 0)) << endl;
	}
}
