#include <iostream>
#include <algorithm>

using namespace std;

const int EMPTY = -987654321; //���� ������ �ʾ��� ���� ��
int board[50], boardSize; //boardSize �ִ� 50
int cache[50][50];

int play(int left, int right) {
	//���� ���: ��� ���� �� �������� ��
	if (left > right)
		return 0;
	int& result = cache[left][right];
	if (result != EMPTY)
		return result;

	//ù��° ���(���� �������� ���)
	result = max(board[left] - play(left + 1, right), board[right] - play(left, right - 1));

	//�ι�° ���
	if (right - left + 1 >= 2)
	{
		result = max(result, -play(left + 2, right)); //���� ���� �ΰ� ����� ���
		result = max(result, -play(left, right - 2)); //������ ���� �ΰ� ����� ���
	}

	return result;
}

void initialize(void) //cache �ʱ�ȭ
{
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			cache[i][j] = EMPTY;
		}
	}
}

int main(void) {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		initialize();
		cin >> boardSize; //�������� ���� ����

		for (int j = 0; j < boardSize; j++)
			cin >> board[j];

		cout << play(0, boardSize - 1) << endl;
	}

	return 0;
}