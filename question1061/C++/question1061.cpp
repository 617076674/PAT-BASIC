#include<iostream>

using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	
	int scores[M];
	int tempNum;
	for(int i = 0; i < M; i++){
		cin >> tempNum;
		scores[i] = tempNum;
	}
	
	int answers[M];
	for(int i = 0; i < M; i++){
		cin >> tempNum;
		answers[i] = tempNum;
	}
	
	int sum;
	for(int i = 0; i < N; i++){
		sum = 0;
		for(int i = 0; i < M; i++){
			cin >> tempNum;
			if(tempNum == answers[i]){
				sum += scores[i];
			}
		}
		cout << sum << endl;
	}
	
	return 0;
}
