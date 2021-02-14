#include <iostream>
#include <algorithm>

using namespace std;

int matrix[100][100], n, yes;
int cache[100][100];
int jump(int x, int y);

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		yes = 0;
		jump(0, 0);  // 0,0���� �����Ѵ�.
		if (yes)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";

		for (int i = 0; i < n; i++)
			fill(cache[i], cache[i] + n, 0);
	}
}

int jump(int x, int y) {  // ���� ��ǥ�� ���� �Լ�
	int a = x, b = y;
	int length = matrix[a][b];

	if (matrix[a][b] == 0) {
		yes = 1;
		return 1;
	}
	if (cache[a][b] == 2)  // 2�̸� �̹� �ι��̳� �Դ� ������ ���� ���� ���� �����Ƿ� return
		return 0;

	if (a + length < n && cache[a][b] == 0) {  // ó�� ���� ��ǥ�� �Ʒ��� �� �� �ִٸ�
		cache[a][b]++;
		jump(a + length, b);
		if (yes)
			return 0;
	}
	if (b + length < n) {  // ���������� �� �� �ִٸ�
		cache[a][b]++;
		jump(a, b + length);
		if (yes)
			return 0;
	}
	return 0;
}