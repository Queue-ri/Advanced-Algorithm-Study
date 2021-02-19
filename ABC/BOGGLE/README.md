# BOGGLE(보글 게임) ![](https://img.shields.io/badge/-easy-brightgreen)
ID | Time Limit | Memory Limit | Source | Category
:-:|:----------:|:------------:|:------:|:--------:
[BOGGLE](https://algospot.com/judge/problem/read/BOGGLE) | 10000ms | 65536kb | [알고리즘 문제 해결 전략](https://algospot.com/judge/problem/list/?source=%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%20%EB%AC%B8%EC%A0%9C%20%ED%95%B4%EA%B2%B0%20%EC%A0%84%EB%9E%B5) | [spoiler](https://algospot.com/judge/problem/list/?tag=%EB%8F%99%EC%A0%81%EA%B3%84%ED%9A%8D%EB%B2%95)
- 1주차 문제 ([#1][i1])

[i1]: https://github.com/Scaachan/Advanced-Algorithm-Study/issues/1

## 📖 문제
![](https://algospot.com/media/judge-attachments/09ee7a6e752f07b0d99b82a010938ab4/boggle.png)

보글(Boggle) 게임은 그림 (a)와 같은 5x5 크기의 알파벳 격자인
게임판의 한 글자에서 시작해서 펜을 움직이면서 만나는 글자를 그 순서대로 나열하여 만들어지는 영어 단어를 찾아내는 게임입니다. 펜은 상하좌우, 혹은 대각선으로 인접한 칸으로 이동할 수 있으며 글자를 건너뛸 수는 없습니다. 지나간 글자를 다시 지나가는 것은 가능하지만, 펜을 이동하지않고 같은 글자를 여러번 쓸 수는 없습니다.

예를 들어 그림의 (b), (c), (d)는 각각 (a)의 격자에서 PRETTY, GIRL, REPEAT을 찾아낸 결과를 보여줍니다.

보글 게임판과 알고 있는 단어들의 목록이 주어질 때, 보글 게임판에서 각 단어를 찾을 수 있는지 여부를 출력하는 프로그램을 작성하세요.
> **주의:** 알고리즘 문제 해결 전략 6장을 읽고 이 문제를 푸시려는 분들은 주의하세요. 6장의 예제 코드는 이 문제를 풀기에는 너무 느립니다. 6장의 뒷부분과 8장을 참조하세요.

### 입력
입력의 첫 줄에는 테스트 케이스의 수 C(C <= 50)가 주어집니다. 각 테스트 케이스의 첫 줄에는 각 5줄에 5글자로 보글 게임판이 주어집니다. 게임판의 모든 칸은 알파벳 대문자입니다.
그 다음 줄에는 우리가 알고 있는 단어의 수 N(1 <= N <= 10)이 주어집니다. 그 후 N줄에는 한 줄에 하나씩 우리가 알고 있는 단어들이 주어집니다. 각 단어는 알파벳 대문자 1글자 이상 10글자 이하로 구성됩니다.

### 출력
각 테스트 케이스마다 N줄을 출력합니다. 각 줄에는 알고 있는 단어를 입력에 주어진 순서대로 출력하고, 해당 단어를 찾을 수 있을 경우 YES, 아닐 경우 NO를 출력합니다.

### 예제 입력
```
1
URLPM
XPRET
GIAET
XTNZY
XOQRS
6
PRETTY
GIRL
REPEAT
KARA
PANDORA
GIAZAPX
```

### 예제 출력
```
PRETTY YES
GIRL YES
REPEAT YES
KARA NO
PANDORA NO
GIAZAPX YES
```
