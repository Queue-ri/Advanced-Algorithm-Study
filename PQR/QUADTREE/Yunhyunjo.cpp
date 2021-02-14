#include <iostream>
#include <string>

using namespace std;

string makeQuadtree();
string str;
int i;

int main(void) {
	int c;
	cin >> c;
	
	while (c--) {
		i = -1;
		cin >> str;
		cout << makeQuadtree() << "\n";
	}
}

// str�� 0���� ���� x�ϰ�� ���ȣ���� ���� ���� ���� �ؼ� �־��ְ� ������ return���� ���� �����ؼ� return

string makeQuadtree(void) {

	i++;

	if (str[i] == 'b' || str[i] == 'w')     // b�� w�� �� ���� return
		return ((str[i] == 'b')? "b":"w");

	string leftUp = makeQuadtree();
	string rightUp = makeQuadtree();
	string leftDn = makeQuadtree();
	string rightDn = makeQuadtree();

	return "x" + leftDn + rightDn + leftUp + rightUp;  // ���� �����ؼ� return

}