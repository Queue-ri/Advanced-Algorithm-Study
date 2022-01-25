#include <iostream>
#include <string>

using namespace std;

int i;
string s;

string quadtree() {

    if (s[i] != 'x') return ((s[i++] == 'b') ? "b" : "w");
    i++;
    string one = quadtree();
    string two = quadtree();
    string three = quadtree();
    string four = quadtree();

    return "x" + three + four + one + two;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    while(n--) {
        i = 0;
        cin >> s;
        cout << quadtree() << "\n";
    }
}