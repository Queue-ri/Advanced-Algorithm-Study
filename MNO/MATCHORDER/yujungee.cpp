//
//  matchOrder.cpp
//  study6
//
//  Created by yujeong on 2021/03/05.
//


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int tc , n;
int rus_r[100], kor_r[100];
vector<int> russian;
vector<int> korean;

int match() {
    sort(korean.begin(), korean.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (korean[j] >= russian[i]) {
                res++;
                korean[j] = 0;
                break;
            }
        }
    }

    return res;
}


int main() {
    cin >> tc;
    while (tc--) {
        cin >> n;
        korean = russian = vector<int>(n);
        for (int i = 0; i < n; i++) {
            cin >> russian[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> korean[i];
        }
        // 정렬 후 함수에 넣기
        sort(russian.begin(), russian.end());
        sort(korean.begin(), korean.end());
        cout << match() << endl;
    }
    return 0;
}

