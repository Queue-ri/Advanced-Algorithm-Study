#include <iostream>
#include <algorithm>

using namespace std;

int tri[100][100];
int cache[100][100];
int n;

int triSum();

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;
	cin >> c;

	while (c--)
	{
		cin >> n;
		cache[0][0] = cache[1][0] = cache[1][1] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i + 1; j++) {
				cin >> tri[i][j];
			}
		}
		
		cout << triSum() << "\n";
	}
}

int triSum() {
	int maxValue = 0, cnt = 0;
	for (int j = 1; j < n; j++) {
		for (int i = 0; i <= j; i++) {
			int a = tri[j][i] + tri[j - 1][i];
			int b = tri[j][i] + tri[j - 1][i - 1];
			tri[j][i] = max(a, b);
			if (a > b) 
				cache[j][i] = cache[j - 1][i];
			else if (a < b) 
				cache[j][i] = cache[j - 1][i - 1];
			else 
				cache[j][i] = cache[j - 1][i - 1] + cache[j - 1][i];
		}
	}

	for (int i = 0; i < n; i++) {
		if (tri[n - 1][i] >= maxValue) {
			if (tri[n - 1][i] == maxValue)
				cnt += cache[n - 1][i];
			else {
				cnt = cache[n - 1][i];
				maxValue = tri[n - 1][i];
			}
		}
	}

	return cnt;
}