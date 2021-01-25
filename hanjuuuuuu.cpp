#include <iostream>
#include <cstring>
#include <string>

using namespace std;

char map[5][5];     //게임판
string words[10];   //찾는 단어
int cache[5][5][10];    //결과 저장    

int dx[8] = { -1, -1, -1, 0, 1, 1, 1, -0 };
int dy[8] = { -1, 0, 1, 1, 1, -0, -1, -1 };

int findWord(const string word, int x, int y, int cnt) {
	if (x < 0 || x >= 5 || y < 0 || y >= 5)     //범위를 벗어날 경우
		return 0;
	int& res = cache[x][y][cnt];
	if (res != -1)      //캐시에 결과값이 있으면 리턴
		return res;
	if (word.size() == 1)
		return res = word[0] == map[x][y];
	if (word[0] != map[x][y])   //단어의 첫글자가 다를 경우
		return res = 0;
	for (int i = 0; i < 8; i++) {
		if (res = findWord(word.substr(1), x + dx[i], y + dy[i], cnt + 1))
			return res;
	}
	return res;
}


int main() {
	int C;      //테스트 케이스의 수
	cin >> C;
	for (int i = 0; i < C; i++) {   //테스트 케이스 수 만큼 반복
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> map[j][k];       //게임판[5][5]생성
			}
		}
		int N;      //찾을 단어의 수
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> words[i];        //찾을 단어 수만큼 단어 입력받기
		}

		for (int i = 0; i < N; i++) {
			memset(cache, -1, sizeof(cache));       //캐시를 -1로 초기화
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