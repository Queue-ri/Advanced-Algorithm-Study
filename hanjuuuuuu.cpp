#include <iostream>
#include <cstring>
#include <string>

using namespace std;

char map[5][5];     //������
string words[10];   //ã�� �ܾ�
int cache[5][5][10];    //��� ����    

int dx[8] = { -1, -1, -1, 0, 1, 1, 1, -0 };
int dy[8] = { -1, 0, 1, 1, 1, -0, -1, -1 };

int findWord(const string word, int x, int y, int cnt) {
	if (x < 0 || x >= 5 || y < 0 || y >= 5)     //������ ��� ���
		return 0;
	int& res = cache[x][y][cnt];
	if (res != -1)      //ĳ�ÿ� ������� ������ ����
		return res;
	if (word.size() == 1)
		return res = word[0] == map[x][y];
	if (word[0] != map[x][y])   //�ܾ��� ù���ڰ� �ٸ� ���
		return res = 0;
	for (int i = 0; i < 8; i++) {
		if (res = findWord(word.substr(1), x + dx[i], y + dy[i], cnt + 1))
			return res;
	}
	return res;
}


int main() {
	int C;      //�׽�Ʈ ���̽��� ��
	cin >> C;
	for (int i = 0; i < C; i++) {   //�׽�Ʈ ���̽� �� ��ŭ �ݺ�
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> map[j][k];       //������[5][5]����
			}
		}
		int N;      //ã�� �ܾ��� ��
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> words[i];        //ã�� �ܾ� ����ŭ �ܾ� �Է¹ޱ�
		}

		for (int i = 0; i < N; i++) {
			memset(cache, -1, sizeof(cache));       //ĳ�ø� -1�� �ʱ�ȭ
			int flag;
			for (int x = 0; x < 5; x++) {
				flag = 0;
				for (int y = 0; y < 5; y++) {
					if (flag = findWord(words[i], x, y, 0))
						break;
				}
				if (flag)
					break;
			}
			cout << words[i] << " " << (flag ? "YES" : "NO") << endl;
		}
	}
	return 0;
}