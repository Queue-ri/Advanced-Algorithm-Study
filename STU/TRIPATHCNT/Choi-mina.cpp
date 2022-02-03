#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int c, n;
int tri[100][100];
int cache_max[100][100];
int cache_path[100][100];

int path(int x, int y) {
	if (x == n - 1) return tri[x][y];
	int& maxpath = cache_max[x][y];
	if (maxpath != -1) return maxpath;
	maxpath = tri[x][y] + max(path(x + 1, y), path(x + 1, y + 1));
	return maxpath;
}

int path_count(int x, int y) {
	if (x == n - 1) return 1;
	int& pathcount = cache_path[x][y];
	if (pathcount != -1) return pathcount;
	pathcount = 0;
	if (path(x + 1, y + 1) >= path(x + 1, y)) pathcount += path_count(x + 1, y + 1);
	if (path(x + 1, y + 1) <= path(x + 1, y)) pathcount += path_count(x + 1, y);
	return pathcount;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> c;
	for (int i = 0; i < c; i++) {
		memset(cache_max, -1, sizeof(cache_max));
		memset(cache_path, -1, sizeof(cache_path));

		cin >> n;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k <= j; k++) {
				cin >> tri[j][k];
			}
		}
		cout << path_count(0, 0) << endl;
	}
	return 0;
}
