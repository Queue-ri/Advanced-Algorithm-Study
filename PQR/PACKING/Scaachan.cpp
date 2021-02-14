#include <bits/stdc++.h>

#define endl '\n'
#define rep(V,S,T) for (int V=S; V<T; ++V)

using namespace std;

int N, W, memo[100][1001];
typedef struct _Element {
	string name;
	int weight;
	int priority;
}Element;
vector<Element> v(100);
vector<string> ans;

int calc(int e, int wsum) {
	if (e >= N) return 0;
	int& cache = memo[e][wsum];
	if (~cache) return cache;

	cache = calc(e + 1, wsum); // not packing e
	if (wsum + v[e].weight <= W) // packing e
		cache = max(cache, calc(e + 1, wsum + v[e].weight) + v[e].priority);

	return cache;
}

void track(int e, int wsum) {
	if (e >= N) return;
	if (calc(e, wsum) == calc(e + 1, wsum)) // e was not packed
		track(e + 1, wsum);
	else { // e was packed
		ans.push_back(v[e].name);
		track(e + 1, wsum + v[e].weight);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int TC; cin >> TC;
	while (TC--) {
		memset(memo, -1, sizeof(memo));
		ans.clear();
		cin >> N >> W;
		rep(i,0,N) cin >> v[i].name >> v[i].weight >> v[i].priority;
		// end of input

		track(0, 0);
		cout << calc(0, 0) << ' ' << ans.size() << endl;
		for (auto str : ans) cout << str << endl;
	}
}
