#include <iostream>
#include <string>
#define endl '\n'

using namespace std;

int idx;

string upside_down(string &cq) {
	char cell = cq[idx++];
	if (cell == 'b' || cell == 'w') return string(1, cell);

	string s1, s2, s3, s4;
	s1 = upside_down(cq);
	s2 = upside_down(cq);
	s3 = upside_down(cq);
	s4 = upside_down(cq);

	return "x" + s3 + s4 + s1 + s2;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int TC; cin >> TC;
	while (TC--) {
		string comp_quad; cin >> comp_quad;
		cout << upside_down(comp_quad) << endl;
		idx = 0;
	}
}
