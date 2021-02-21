//
//  dakyommii.cpp
//  DRAGON
//
//  Created by 다곰 on 2021/02/20.
//

#include <iostream>
using namespace std;

const string s = "FX";  //0세대 문자열
int len[51];    //각 차원 X,Y 길이 저장
const int MAX = 1000000000 + 1; //p의 최대길이

//각 차원 최소 길이 저장하는 함수
void lenCnt() {
    len[0] = 1; //0차원에서는 FX라서 X 길이 1
    for (int i = 1; i < 51; i++)
        len[i] = min(MAX, len[i-1] * 2 + 2);    //X->X+YF로 치환한 것과 같은 원리
}

char change(int N, int skp, const string& S) {    //skp: 출력 하려고 하는 문자열 판단 위한 변수
    if (N == 0) return S[skp];  //0차원이면 그냥 반환
    
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'X' || S[i] == 'Y') {
            //skp를 차원의 최소문자 길이와 비교해서 skp가 더 작은 시점에는 차원을 모두 돌아서 최종적으로 출력해야할 시점
            
            if (skp >= len[N]) skp -= len[N];
            else if(S[i] == 'X')    //X자리 대체
                return change(N-1, skp, "X+YF");
            
            else if(S[i] == 'Y')    //Y자리 대체
                return change(N-1, skp, "FX-Y");
        }
        else if(skp > 0) --skp; //이 경우는 F,+,-인 경우이므로 다음 문자 검사하기 위해 skp 줄임
        else return S[i];   //최종 문자 return
    }

    return '#'; //오류
}

int main() {

    int c, n, p, l;
    
    cin >> c;
    
    lenCnt();
    
    while (c--) {
        cin >> n >> p >> l; //n:차원
        for (int i = 0; i < l; i++)  {//l개 문자 출력하기 위한 for문
            cout << change(n, p + i - 1, s);
            //skp = p + i - 1
        }
        cout << endl;
    }
    
    
}
