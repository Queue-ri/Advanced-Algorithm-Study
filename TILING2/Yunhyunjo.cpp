#include <iostream>

using namespace std;

int sum[100] = { 1,2,3, };
int n;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 3; i < 100; i++) {  // 3번째 부터 값이 i-2값 더하기 i-1값이므로 계산해서 넣어준다.
		sum[i] = (sum[i - 2] + sum[i - 1]) % 1000000007;
	}

	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		cout << sum[n-1] << "\n";
	}
}
