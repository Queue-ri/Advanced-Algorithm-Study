#include <iostream>
#include <cstring>
using namespace std;

int c, position;
string picture;

string quad() {
	char head = picture[position++];

	if (head == 'w' || head == 'b') {
		return string(1, head);
	}
	else {
		string leftUpper = quad();
		string rightUpper = quad();
		string leftLower = quad();
		string rightLower = quad();
		return 'x' + leftLower + rightLower + leftUpper + rightUpper;
	}
}

int main() {
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> picture;
		cout << quad() << endl;
		position = 0;
	}
	return 0;
}
