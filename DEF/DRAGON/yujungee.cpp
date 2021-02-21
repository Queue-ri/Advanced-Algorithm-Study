#include <iostream>
#include <cstring>
using namespace std;

int tc, n, p, l;
const int Max = 1000000000;
const string  X = "X+YF";
const string  Y = "FX-Y";
int len[51];

char draw(const string& dragon, int generation, int skip)
{
    if (generation == 0) {
        if (skip > dragon.size()) return 0;
        return dragon[skip];
    }
    
    for (int i = 0; i < dragon.size(); i++) {
        if (dragon[i] == 'X' || dragon[i] == 'Y') {
            if (skip >= len[generation]) skip -= len[generation];
            else if (dragon[i] == 'X')
                return draw(X, generation - 1, skip);
            else
                return draw(Y, generation - 1, skip);
        }
        else if (skip > 0) --skip;
        else return dragon[i];
    }
    return 0;
}

int main()
{
    
    len[0] = 1;
    for (int i = 1; i <= 50; i++) {
        len[i] = min(Max, len[i - 1] * 2 + 2);
    }
    
    cin >> tc;
    
    while (tc--) {
        cin >> n >> p >> l;
        for (int i = 0; i < l; i++)
            cout << draw("FX", n, p + i - 1);
        cout << endl;
    }
}
