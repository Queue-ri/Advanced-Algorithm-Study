#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int TC; cin >> TC;
	while (TC--) {
		int N; cin >> N;
		
		priority_queue<int, vector<int>, greater<int>> pq;
		while (N--) {
			int _; cin >> _;
			pq.push(_);
		}
		
		int ans = 0;
		while(pq.size() > 1) {
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();

			ans += a + b;
			pq.push(a + b);
		}
		cout << ans << endl;
	}
}
