#include<iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int tempNum;

	int counts[N + 1];	//counts[i](i != N)��ʾ����i���������
	int greaterThanN = 0; //greaterThanN�д洢�ﳵ����N���������
	for(int i = 0; i < N + 1; i++) {
		counts[i] = 0;
	}

	for(int i = 0; i < N; i++) {
		cin >> tempNum;
		if(tempNum <= N) {
			counts[tempNum]++;
		} else {
			greaterThanN++;
		}
	}

	int greaterCounts[N + 1];//greaterCounts[i]��ʾ�ﳵ����i���������
	greaterCounts[N] = greaterThanN;
	for(int i = N - 1; i >= 0; i--) {
		greaterCounts[i] = greaterCounts[i + 1] + counts[i + 1];
	}

	for(int i = N; i >= 0; i--) {
		if(greaterCounts[i] >= i) {
			cout << i << endl;
			break;
		}
	}

	return 0;
}
