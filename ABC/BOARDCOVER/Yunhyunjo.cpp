#include <iostream>
#include <string>

using namespace std;

int map[20][20]; // board
int white; // 흰칸
int w, h; // 검은 칸
int cnt; // 방법의 수
void start();
int findL();
int startxy[2]; // 흰 칸이 처음 시작되는 위치
int arr[4][4] = { { 0,1,1,1 },{ 1,0,1,-1 },{ 1,0,1,1 },{ 0,1,1,0 } };  // L자 블록의 경우의 수

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
			for (int j = 0; j < w; j++) {  // board 세팅 및 흰 칸 수 세기
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

void start() {  // 흰 칸의 위치를 찾는 함수
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
int findL() {  // L자 블록으로 채울 수 있는지 찾는 함수
	start();  // 흰 칸의 위치를 찾는 함수
	int i = startxy[0];
	int j = startxy[1];

	if (white == 0) {
		cnt++;
		return 0;
	}

	for (int k = 0; k < 4; k++) {
		int one = arr[k][0] + i, two = arr[k][1] + j, three = arr[k][2] + i, four = arr[k][3] + j;
		if (one < h && one >= 0 && two < w && two >= 0 && three < h && three >= 0 && four >= 0 && four < w) {  // 보드의 영역을 벗어나지 않도록
			if (!map[one][two] && !map[three][four]) {  // L자 블록을 채울 수 있을 때
				map[one][two] = 1;
				map[three][four] = 1;
				map[i][j] = 1;							// L자 블록을 채운다
				white -= 3;  // 남은 흰 칸의 갯수 
				findL();  // 재귀 호출을 통해 반복
				map[one][two] = 0;
				map[three][four] = 0;
				map[i][j] = 0;  // 다른 방법도 찾기 위해 방금 채운 L자 블록을 초기화 한다.
				white += 3;
			}
		}
	}
	return 0;
}