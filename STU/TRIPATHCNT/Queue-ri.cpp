#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define rep(V,S,T) for(int V=S; V<T; ++V)

using namespace std;

int N;
int tri[100][100], s[100][100], c[100][100];

int find_path(int y, int x) {
	int &s_cache = s[y][x], &c_cache = c[y][x];
	if (y == N - 1) {
		c_cache = 1;
		return tri[y][x];
	}
	if (s_cache) return s_cache;

	int a = find_path(y + 1, x);
	int b = find_path(y + 1, x + 1);

	if (a < b) c_cache = c[y + 1][x + 1];
	else if (a > b) c_cache = c[y + 1][x];
	else c_cache = c[y + 1][x] + c[y + 1][x + 1];

	return s_cache = max(a, b) + tri[y][x];
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int TC; cin >> TC;
	while (TC--) {
		cin >> N;
		rep(i, 0, N)
			rep(j, 0, i+1)
				cin >> tri[i][j];

		memset(s, 0, sizeof(s));
		find_path(0, 0);
		cout << c[0][0] << endl;
	}
}
