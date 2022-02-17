#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int C;

vector <int> match(const string &rs) {
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

int palindrome(const string &s, const string &rs) {
	vector <int> pi = match(rs);
	int m = s.size(), n = rs.size();
	int begin = 0, matched = 0;
	
	while (begin < n) {
		// s의 글자가 rs의 글자와 같은 경우
		if (s[begin + matched] == rs[matched]) {
			++matched;
			
			// 마지막 문자까지 다 보고 겹치는 부분의 길이 반환
			if (begin + matched == n)
				return matched;
		}
		// 두 글자가 같지 않은 경우
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

int main() {
	cin >> C;

	for (int i = 0; i < C; i++) {
		string S, reverseS;
		cin >> S;

		for (int j = S.size() - 1; j >= 0; j--)
			reverseS += S[j];

		cout << S.size() * 2 - palindrome(S, reverseS) << endl;
	}

	return 0;
}
