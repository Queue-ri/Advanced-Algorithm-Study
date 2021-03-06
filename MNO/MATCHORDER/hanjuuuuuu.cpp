#include<iostream>
#include<algorithm>
using namespace std;

int N;
int rus_r[100], kor_r[100];		//팀별 레이팅

int order(int* russia,int* korea) {
	int index_r = 0;
	int	index_k = 0;

	while(index_k < N){
		//우리팀 레이팅이 크거나 같으면 인덱스 함께 증가(매칭)
		if (russia[index_r] <= korea[index_k]){
			index_r += 1;
			index_k += 1;
		}
		//그렇지 않으면, 우리팀 다음 인덱스와 비교
		//작은 레이팅을 상대팀 제일 큰 레이팅과 비교하게 만듦
		else{
			index_k += 1;
		}

	}
	//이길 수 있는 사람의 수가 최대 승의 값
	return index_r;

}

int main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> N;
		for(int i = 0; i < N; i++) {
			cin >> rus_r[i];
		}
		for (int j = 0; j < N; j++) {
			cin >> kor_r[j];
		}
		sort(rus_r, rus_r + N);
		sort(kor_r, kor_r + N);
		cout << order(rus_r, kor_r) << endl;
	}
}