#include <iostream>
using namespace std;


int main() {
   
    // 첫번째 입력: 테스트 갯수
    int c, N, L;
    cin >> c;
    
    // c번만큼 반복문 돌림
    while(c--) {
        // 두번째 입력: 공연장을 대여할 수 있는 날들의 수 N (1 ≤ N ≤ 1000) 이미 섭외한 공연 팀의 수 L (1 ≤ L ≤ 1000, L ≤ N)
        cin >> N >> L;
        // 세번째 입력: N개의 숫자로 날짜별 공연장 대여 비용.
        int cost[1001];
        for (int i = 0; i < N; i++) {
                cin >> cost[i]; // 배열에 비용 저장
        }
        
        double answer = 9999;
        
        for (int i = 0; i < N; ++i){
            double sum = 0;
            for (int j=i; j<N; j++) {
                sum += cost[j]; 
                if (j-i+1 >= L && sum/ (j-i+1) < answer) {
                   answer =sum/(j-i+1);
                }
            }
        }
        cout << fixed;
        cout.precision(11);
        cout << answer << endl;
    }
    
    
    return 0;
}
