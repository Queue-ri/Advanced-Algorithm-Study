#include<iostream>
using namespace std;

int main() {
  int C;        //테스트 케이스의 수 
  cin >> C;
  for(int i = 0; i < C; i++) {      //테스트 케이스 수만큼 반복
    int N, L;   //공연장 대여 가능한 날들의 수와 섭외한 공연팀의 수
    cin >> N >> L;
    int cost[1001];     //공연장 대여 비용 배열

    for (int i = 0; i < N; i++) 
        cin >> cost[i];     //공연장 대여 비용 입력받기

    double min = 100;    //최소비용 변수
    for (int i = 0; i < N; i++) {   //공연장 대여 가능한 날만큼 반복
        double sum = 0;       //비용 합 변수
        int count = 0;     //공연일 수 변수
        for (int j = i; j < N; j++) {   //연속된 부분중 최소합 구하기 위해 반복
            sum += cost[j];
            count++;
            if (count >= L && sum / count < min)    //L개팀 이상이고, 구간 내 최소평균일 경우
                min = sum / count;
        }
    }
    cout << fixed;
    cout.precision(11);
    cout << min << endl;     
  }

  return 0;
}