#include<iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
	
	int counts[101];
	for(int i = 0; i < 101; i++){
		counts[i] = 0;
	}
	
	int tempNum;
	for(int i = 0; i < N; i++){
		cin >> tempNum;
		counts[tempNum]++;
	}
	
	int K;
	cin >> K;
	for(int i = 0; i < K; i++){
		cin >> tempNum;
		cout << counts[tempNum];
		if(i != K - 1){
			cout << " ";
		}
	}
} 
