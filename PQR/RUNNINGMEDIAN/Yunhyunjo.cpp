#include <iostream>
#include <queue>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int c, n, a, b, sum, tmp, now;
	long long p;
	cin >> c;

	while (c--) {
		cin >> n >> a >> b;
		priority_queue <int, vector <int>, greater<int>> low;
		priority_queue <int> high;
		p = 1983;
		sum = 1983;
		high.push(p);
		for (int i = 1; i < n; i++) {
			now = ((p * a) + b) % 20090711;
			if (high.size() == low.size()) high.push(now);
			else low.push(now);
			if (high.top() > low.top()) {
				tmp = high.top();
				high.pop();
				high.push(low.top());
				low.pop();
				low.push(tmp);
			}
			sum += (high.top() % 20090711);
			p = now;
			sum %= 20090711;
		}
		cout << sum << "\n";
	}

	return 0;
}
