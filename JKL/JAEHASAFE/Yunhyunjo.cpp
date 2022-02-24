#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getLPS(string N) {
	int m = N.size();
	vector<int> pi(m, 0);

	int begin = 1, matched = 0;
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

int shift(string a, string b) {

	vector <int> p = getLPS(b);

	int begin = 0, matched = 0;

	while (begin <= a.size() - b.size())
	{
		if (a[begin + matched] == b[matched]) {
			++matched;
			if (matched == b.size()) return begin;
		}
		else {
			if (matched == 0) ++begin;
			else {
				begin += matched - p[matched - 1];
				matched = p[matched - 1];
			}
		}
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int c;
	cin >> c;
	while (c--) {
		int n;
		cin >> n;
		vector <string> v(n + 1);
		for (int i = 0; i <= n; i++) {
			cin >> v[i];
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 1) sum += shift(v[i] + v[i], v[i + 1]);
			else sum += shift(v[i + 1] + v[i + 1], v[i]);
		}
		cout << sum << "\n";
	}
}
