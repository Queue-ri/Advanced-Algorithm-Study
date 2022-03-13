#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
// sortt[vector] = vector를 정렬시키는데 필요한 뒤집기 횟수
map<vector<int>, int> sortt;

// 뒤집기 횟수 계산
void bfs(int n) {
	vector<int> p(n);
  // 배열 초기화
	for (int i = 0; i < n; i++)
		p[i] = i;
	queue<vector<int>> q;
	q.push(p);
	sortt[p] = 0;
	while (!q.empty()) {
		vector<int> here = q.front();
		q.pop();
		// 현재 비용
		int cost = sortt[here];
		// 모든 뒤집기 상황 고려
		for (int i = 0; i < n; i++)
			for (int j = i + 2; j <= n; j++) {
				reverse(here.begin() + i, here.begin() + j);
				// 배열을 뒤집었을때 아직 계산이 안된 배열이면
				if (sortt.count(here) == 0) {
					// 현재 배열 비용에 +1
					sortt[here] = cost + 1;
					q.push(here);
				}
				// 배열 원상복구
				reverse(here.begin() + i, here.begin() + j);
			}
	}
}

int solve(const vector<int>& p) {
	int n = p.size();
  // p을 [0, ..., n-1]로 변환
	vector<int> fixed(n);
	for (int i = 0; i < n; i++) {
		int small = 0;
		for (int j = 0; j < n; j++)
			if (p[j] < p[i])
				small++;
		fixed[i] = small;
	}
	return sortt[fixed];
}

int main() {
	for (int i = 1; i <= 8; i++)
		bfs(i);
	int C;
	cin >> C;
	while (C--) {
		int N;
		cin >> N;
		vector<int> v;
		int value;
		for (int i = 0; i < N; i++) {
			cin >> value;
			v.push_back(value);
		}
		cout << solve(v) << endl;
	}
}
