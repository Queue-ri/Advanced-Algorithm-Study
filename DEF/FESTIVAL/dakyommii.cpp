//
//  dakyommii.cpp
//  FESTIVAL_PR
//
//  Created by 다곰 on 2021/01/23.
//

#include <iostream>
using namespace std;

double solution(int l, int N, int c[]) {    //공연 일수에 따른 최소 평균 비용 계산
    double cost = 0, min = 0;
    for (int i = l; i <= N; i++) {   //공연 일수 조정
        for (int j = 0; j <= N-i; j++) {   //공연 시작일 조정
            
            for (int k = 0; k < i; k++)
                    cost += c[j + k];
        
            cost = cost / i;
            if (min > cost || min == 0) min = cost;
            cost = 0;
        }
    }
    return min;
}

int main() {
    //입력
    int C,N,L;
    cin >> C;   //테스트 케이스
    
    double *sol = new double[C];  //결과 저장할 배열
    
    for (int i = 0; i < C; i++) {
        cin >> N >> L;  //대여 가능 일, 이미 섭외한 공연 팀 수
        
        //날짜별 대여 비용
        int *cost = new int[N];
        for (int j =0 ; j < N; j++)
            cin >> cost[j];
        
        sol[i] = solution(L, N, cost);
        
        
    }
    
    
    
    
    //출력
    for (int i = 0; i < C; i++) {
        cout << fixed;
        cout.precision(11);
        cout << sol[i] << endl;
    }
}
