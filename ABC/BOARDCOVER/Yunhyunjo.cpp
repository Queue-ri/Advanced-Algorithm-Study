#include <iostream>
#include <string>

using namespace std;

int map[20][20]; // board
int white; // ��ĭ
int w, h; // ���� ĭ
int cnt; // ����� ��
void start();
int findL();
int startxy[2]; // �� ĭ�� ó�� ���۵Ǵ� ��ġ
int arr[4][4] = { { 0,1,1,1 },{ 1,0,1,-1 },{ 1,0,1,1 },{ 0,1,1,0 } };  // L�� ����� ����� ��

int main(void) {
	int c;
	cin >> c;
	while (c--)
	{
		cin >> h >> w;
		string str;
		cnt = 0;
		white = 0;
		for (int i = 0; i < h; i++) {
			cin >> str;
			for (int j = 0; j < w; j++) {  // board ���� �� �� ĭ �� ����
				if (str[j] == '#') {
					map[i][j] = 1;
				}
				else {
					map[i][j] = 0;
					white++;
				}
			}
		}
		if (white % 3 == 0) {
			findL();
		}
		cout << cnt << "\n";
	}
}

void start() {  // �� ĭ�� ��ġ�� ã�� �Լ�
	bool x = false;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (!map[i][j]) {
				startxy[0] = i;
				startxy[1] = j;
				x = true;
				break;
			}
		}
		if (x) break;
	}
}
int findL() {  // L�� ������� ä�� �� �ִ��� ã�� �Լ�
	start();  // �� ĭ�� ��ġ�� ã�� �Լ�
	int i = startxy[0];
	int j = startxy[1];

	if (white == 0) {
		cnt++;
		return 0;
	}

	for (int k = 0; k < 4; k++) {
		int one = arr[k][0] + i, two = arr[k][1] + j, three = arr[k][2] + i, four = arr[k][3] + j;
		if (one < h && one >= 0 && two < w && two >= 0 && three < h && three >= 0 && four >= 0 && four < w) {  // ������ ������ ����� �ʵ���
			if (!map[one][two] && !map[three][four]) {  // L�� ����� ä�� �� ���� ��
				map[one][two] = 1;
				map[three][four] = 1;
				map[i][j] = 1;							// L�� ����� ä���
				white -= 3;  // ���� �� ĭ�� ���� 
				findL();  // ��� ȣ���� ���� �ݺ�
				map[one][two] = 0;
				map[three][four] = 0;
				map[i][j] = 0;  // �ٸ� ����� ã�� ���� ��� ä�� L�� ����� �ʱ�ȭ �Ѵ�.
				white += 3;
			}
		}
	}
	return 0;
}