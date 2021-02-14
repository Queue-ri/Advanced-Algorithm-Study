#include <bits/stdc++.h>

#define rep(V,S,T) for(int V = S; V < T; ++V)
#define endl '\n'

using namespace std;

char bog[7][7]; // padding
int memo[7][7][10];
string word;
int word_len;
const int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int dfs(int y, int x, int n) {
	if (n >= word_len - 1) return 1; // no need to cache
	int& cache = memo[y][x][n];
	if (~cache) return cache;
	
	rep(i, 0, 8) {
		int ny = y + dy[i], nx = x + dx[i];
		if (bog[ny][nx] == word[n + 1]) cache = dfs(ny, nx, n + 1);
		if (cache == 1) return cache;
	}
	return cache = 0;
}

inline bool exist() {
	rep(i, 1, 6)
		rep(j, 1, 6)
			if (bog[i][j] == word[0])
				if (dfs(i, j, 0)) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int TC; cin >> TC;
	while (TC--) {
		rep(i, 1, 6)
			cin >> bog[i][1] >> bog[i][2] >> bog[i][3] >> bog[i][4] >> bog[i][5];
		
		int N; cin >> N;
		while (N--) {
			memset(memo, -1, sizeof(memo));
			cin >> word; // end of input
			word_len = word.length();
			cout << word + (exist() ? " YES" : " NO") << endl;
		}
	}
}
