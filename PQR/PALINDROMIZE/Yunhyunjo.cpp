#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> getLPS(string N) {
    int m = N.size();
    vector<int> pi(m, 0);

    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (N[begin + matched] == N[matched]) {
            ++matched;
            pi[begin + matched - 1] = matched;
        }
        else {
            if (matched == 0)
                ++begin;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

int PALINDROMIZE(string a, string b) {
    int n = a.size(), m = b.size();
    vector<int> pi = getLPS(b);

    int begin = 0, matched = 0;
    while (begin < n) {
        if (matched < m && a[begin + matched] == b[matched]) {
            ++matched;
            if (begin + matched == n)
                return matched;
        }
        else {
            if (matched == 0)
                ++begin;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;
    while (c--) {
        string str, restr;
        cin >> str;
        restr = str;
        reverse(restr.begin(), restr.end());
        cout << str.length() * 2 - PALINDROMIZE(str, restr) << endl;
    }
}
