#include <iostream>
#include <string>
#include <stack>
using namespace std;
int c;
string s;

bool bracket() {
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			st.push(s[i]);
		}
		if (s[i] == ')') {
			if (st.empty() || st.top() != '(') return false;
			st.pop();
		}
		if (s[i] == '}') {
			if (st.empty() || st.top() != '{') return false;
			st.pop();
		}
		if (s[i] == ']') {
			if (st.empty() || st.top() != '[') return false;
			st.pop();
		}
	}
	return st.empty() ? true : false;
}

int main() {
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> s;
		if (bracket() == true) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

	}
	return 0;
}
