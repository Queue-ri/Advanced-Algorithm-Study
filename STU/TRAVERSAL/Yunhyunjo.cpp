#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> slice(const vector<int>& v, int a, int b) {
	return vector<int>(v.begin() + a, v.begin() + b);
}
  
void printPostOrder(const vector <int>& po, const vector <int>& io){
	if (po.empty()) return;
	int N = po.size();
	int root = po[0];
	int L = find(io.begin(), io.end(), root) - io.begin();
	int R = N - 1 - L;

	printPostOrder(slice(po, 1, L + 1), slice(io, 0, L));
	printPostOrder(slice(po, L + 1, N), slice(io, L + 1, N));
	cout << root << " ";
	return;
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
		vector <int> p(n);
		vector <int> m(n);
		vector <int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> m[i];
		}
		printPostOrder(p, m);
	}
}
