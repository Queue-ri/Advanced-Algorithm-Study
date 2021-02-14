#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;
int startArr[10000];
int levelArr[10000][3];
int minLevel(int start);
int currentLevel(int len, int start);
int oneLevel(int len, int start);
int twoLevel(int len, int start);
int fourLevel(int len, int start);
int fiveLevel(int len, int start);

int main(void) {
	int n;

	cin >> n;
	while (n--)
	{
		cin >> s;
		fill(startArr, startArr + 10000, 0);
		for (int i = 0; i<10000; i++)
			fill(levelArr[i], levelArr[i] + 10000, 0);
		cout << minLevel(0) << "\n";
	}
}

int minLevel(int start) {
	int size = s.size() - start, three = 999999999, four = 999999999, five = 999999999;
	if (size == 0)
		return 0;
	if (startArr[start] != 0)
		return startArr[start];
	if (size > 2)
		three = currentLevel(3, start) + minLevel(start + 3);
	if (size > 3)
		four = currentLevel(4, start) + minLevel(start + 4);
	if (size > 4)
		five = currentLevel(5, start) + minLevel(start + 5);

	int min = (three < four) ? three : four;
	startArr[start] = (min < five) ? min : five;
	return startArr[start];
}

int currentLevel(int len, int start) {
	if (levelArr[start][len - 3] != 0)
		return levelArr[start][len - 3];
	if (oneLevel(len, start))
		return 1;
	else if (twoLevel(len, start))
		return 2;
	else if (fourLevel(len, start))
		return 4;
	else if (fiveLevel(len, start))
		return 5;
	else {
		levelArr[start][len - 3] = 10;
		return 10;
	}
}

int oneLevel(int len, int start) {
	int first = s[start] - 48;
	for (int i = start + 1; i < start + len; i++) {
		if (s[i] - 48 != first)
			return 0;
	}
	levelArr[start][len - 3] = 1;
	return 1;
}

int twoLevel(int len, int start) {
	int a;
	if ((s[start] - 48) - (s[start + 1] - 48) == 1)
		a = -1;
	else if ((s[start] - 48) - (s[start + 1] - 48) == -1)
		a = 1;
	else
		return 0;
	for (int i = start + 1; i < start + len; i++) {
		if (s[i] - 48 == (s[i - 1] - 48) + a)
			continue;
		else
			return 0;

	}
	levelArr[start][len - 3] = 2;
	return 1;
}

int fourLevel(int len, int start) {
	int first = s[start] - 48;
	int second = s[start + 1] - 48;
	if (first == second)
		return 0;
	for (int i = start + 2; i < start + len; i++) {
		if (s[i] - 48 != s[i - 2] - 48)
			return 0;
	}
	levelArr[start][len - 3] = 4;
	return 1;
}

int fiveLevel(int len, int start) {
	int d = (s[start + 1] - 48) - (s[start] - 48);
	for (int i = start; i < start + len - 1; i++) {
		if ((s[i] - 48) + d != s[i + 1] - 48)
			return 0;
	}
	levelArr[start][len - 3] = 5;
	return 1;
}