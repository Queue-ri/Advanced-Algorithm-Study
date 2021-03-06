#include<iostream>
#include<algorithm>
using namespace std;

int N;
int rus_r[100], kor_r[100];		//���� ������

int order(int* russia,int* korea) {
	int index_r = 0;
	int	index_k = 0;

	while(index_k < N){
		//�츮�� �������� ũ�ų� ������ �ε��� �Բ� ����(��Ī)
		if (russia[index_r] <= korea[index_k]){
			index_r += 1;
			index_k += 1;
		}
		//�׷��� ������, �츮�� ���� �ε����� ��
		//���� �������� ����� ���� ū �����ð� ���ϰ� ����
		else{
			index_k += 1;
		}

	}
	//�̱� �� �ִ� ����� ���� �ִ� ���� ��
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