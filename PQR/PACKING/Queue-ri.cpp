#include <iostream>
#include <vector>
#include <cstring>
#define endl '\n'
#define rep(V,S,T) for(int V=S; V<T; ++V)

using namespace std;

char item[101][21];
int N, W, item_w[101], want[101], memo[101][1001];

int pack(int i, int capacity) {
	if (i > N) return 0;
	int &cache = memo[i][capacity];
	if (~cache) return cache;

	if (item_w[i] <= capacity)
		cache = pack(i + 1, capacity - item_w[i]) + want[i];
	return cache = max(cache, pack(i + 1, capacity));
}

int count(int capacity, vector<int> &packed) {
	int sum = 0;
	rep(i, 1, N + 1) {
		if (pack(i, capacity) != pack(i+1, capacity)) {
			sum += 1;
			capacity -= item_w[i];
			packed.push_back(i);
		}
	}
	return sum;
}

int main() {
	int TC; cin >> TC;
	while (TC--) {
		cin >> N >> W;
		rep(i, 1, N+1) cin >> item[i] >> item_w[i] >> want[i];
		memset(memo, -1, sizeof(memo));
		vector<int> packed;
		cout << pack(1, W) << ' ' << count(W, packed) << endl;
		for (auto i : packed) puts(item[i]);
	}
}
