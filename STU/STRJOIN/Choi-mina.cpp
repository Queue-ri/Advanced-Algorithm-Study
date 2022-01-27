#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int c, n;
int cost;

int con(const vector<int> len) {
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < len.size(); i++) {
		q.push(len[i]);
	}
	cost = 0;
	while (q.size() > 1) {
		int min1 = q.top();
		q.pop();
		int min2 = q.top();
		q.pop();
		q.push(min1 + min2);
		cost += (min1 + min2);
	}

	return cost;
}

int main() {
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n;
		vector<int> len(n);
		for (int j = 0; j < n; j++) {
			cin >> len[j];
		}
		cout << con(len) << endl;
	}
	return 0;
}
