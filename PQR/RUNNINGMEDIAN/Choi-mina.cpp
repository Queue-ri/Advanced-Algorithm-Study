#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 
int C, N, a, b;

int running_median() {
	long long seed = 1983;

	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int sum = 1983;
	maxHeap.push(seed);

	for (int i = 1; i < N; i++) {
		int now = ((seed * a) + b) % 20090711;
		if (maxHeap.size() == minHeap.size())
			maxHeap.push(now);
		else
			minHeap.push(now);

		if (!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
			int top1 = maxHeap.top(), top2 = minHeap.top();
			maxHeap.pop();
			minHeap.pop();
			maxHeap.push(top2);
			minHeap.push(top1);
		}
		sum = (sum + maxHeap.top()) % 20090711;
		seed = now;
		sum %= 20090711;
	}
	return sum;
}

int main()
{
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N >> a >> b;
		cout << running_median() << endl;
	}
	return 0;
}
