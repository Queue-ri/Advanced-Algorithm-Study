//
//  yujungee.cpp
//  TILING2
//
//  Created by yujeong on 2021/01/30.
//

#include <iostream>
#include<string.h>
using namespace std;
const int mod = 1000000007;

int n;
int cache[101];

int tiling(int width) {
    
    if (width <= 1) return 1;

    int& res = cache[width];
    if (res != -1) return res;
    
    return res = (tiling(width-2) + tiling(width-1)) % mod;
}


int main() {
    int tc;
    cin >> tc;

    while(tc--) {
        memset(cache, -1, sizeof(cache));
        cin >> n;

        cout << tiling(n) << endl;
    }
}
