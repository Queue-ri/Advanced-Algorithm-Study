#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int c;

	cin >> c;

	while (c--) {
		string str;
		cin >> str;

		stack <char> s;
		bool flag = true;
		for (char ch: str) {
			if(ch == '[') s.push('[');
			else if (ch == '{') s.push('{');
			else if (ch == '(') s.push('(');
			else if (ch == ']'){
				if (!s.empty() && s.top() == '[') s.pop();
				else {
					flag = false;
					break;
				}
			}
			else if (ch == '}') {
				if (!s.empty() && s.top() == '{') s.pop();
				else {
					flag = false;
					break;
				}
			}
			else {
				if (!s.empty() && s.top() == '(') s.pop();
				else {
					flag = false;
					break;
				}
			}
		}
		if (flag && s.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
