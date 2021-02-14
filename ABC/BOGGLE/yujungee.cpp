#include <iostream>
#include <cstring>
using namespace std;
char matrix[5][5];  //  보글 게임판을 만든다.
string words[10];   // 단어를 저장할 배열
int position[10][5][5]; // 각 글자에 해당하는 x와 y 좌표의 위치
int N; // 입력받을단어 수
int memo[5][5][10];
int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };    // dx
int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };    // dy      dx는 좌측 -> 중간 -> 우측, dy는 하 -> 중 -> 상 기준
int findWord(const string word, int x, int y, int num) {
    if (x < 0 || x >= 5 || y < 0 || y >= 5) return 0;   // matrix 범위를 넘어갔을 때
    if (word.size() == 1)
        return word[0] == matrix[x][y]; // 단어가 한 글자 일 때 일치하면 바로 return
    int& cache = memo[x][y][num];
    if (~cache) return cache;
    int tORf = position[num][x][y]; // 일치하면 넣어줄 곳
    if (word[0] != matrix[x][y]) return cache = 0; //일치하지 않으면 0
    for (int i = 0; i < 8; i++) {   // dx와 dy를 더해주고 재귀를 통해 확인
        if (tORf = findWord(word.substr(1), x + dx[i], y + dy[i], num + 1))
            return cache = tORf;
    }
    return cache = tORf;
}
int main() {
    int c;  // 테스트 횟수
    cin >> c;   // test 수 입력받음.
    while (c--) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> matrix[i][j];
            }
        } // boggle판 입력받음
        
        cin >> N; //체크 할 단어 수
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        } // 단어 입력받음
        for (int i = 0; i < N; i++) {
            memset(memo, -1, sizeof(memo));
            int answer;
            for (int x = 0; x < 5; x++) {
                answer = 0;   // answer을 반복문 마다 0 설정
                for (int y = 0; y < 5; y++) {
                    if (answer = findWord(words[i], x, y, 0)) break; // 일치 할 경우
                }
                if (answer) break;
            }
            cout << words[i] << " " << (answer ? "YES" : "NO") << endl; // 출력문
        }
    }
    return 0;
}
