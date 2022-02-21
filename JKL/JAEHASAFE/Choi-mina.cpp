#include <iostream>
#include <string>
#include <vector>
using namespace std;
int T, N;

vector <int> match(const string& rs) {
	vector<int> pi(rs.size(), 0);
	int begin = 1, matched = 0;

	while (begin + matched < rs.size()) {
		// begin+matched에 있는 문자와 matched에 있는 문자가 같은 경우
		if (rs[begin + matched] == rs[matched]) {
			++matched;
			pi[begin + matched - 1] = matched;
		}
		// 다른 경우
		else {
			// matched가 0인 경우에는 다음칸부터 계속해서 계산
			if (matched == 0)
				++begin;
			else {
				// 시작위치를 (matched - 일치하는 접두사와 접미사가 길이)만큼 빼서 이동
				begin += matched - pi[matched - 1];
				// begin을 옮기고 나서도 pi[matched - 1]만큼은 같으니까
				// matched = pi[matched - 1]
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

int kmp(const string& s, const string& rs) {
	vector <int> pi = match(rs);
	int m = s.size(), n = rs.size();
	int begin = 0, matched = 0;

	while (begin <= m - n) {
		// s의 글자가 rs의 글자와 같은 경우
		if (s[begin + matched] == rs[matched]) {
			++matched;

			// 마지막 문자까지 다 보고 겹치는 부분의 길이 반환
			if (matched == n)
				return begin;
		}
		else {
			// matched가 0인 경우에는 다음칸부터 계속해서 계산
			if (matched == 0)
				++begin;
			else {
				// 시작위치를 (matched - 일치하는 접두사와 접미사가 길이)만큼 빼서 이동
				begin += matched - pi[matched - 1];
				// begin을 옮기고 나서도 pi[matched - 1]만큼은 같으니까
				// matched = pi[matched - 1]
				matched = pi[matched - 1];
			}
		}
	}
	return 0;
}

int shifts(const string& original, const string& target) {
	return kmp(original + original, target);
}
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;

		vector<string> s(N + 1);
		for (int j = 0; j <= N; j++) {
			cin >> s[j];
		}
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0)	//시계방향으로 돌림
				sum += shifts(s[i+1], s[i]);
			else //반시계방향으로 돌림
				sum += shifts(s[i], s[i+1]);
		}
		cout << sum << endl;
	}
	return 0;
}
