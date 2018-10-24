#include<iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	int queue[100001];
	for(int i = 0; i < 100001; i++){
		queue[i] = 0;
	}
	
	int tempQueue;
	int tempScore;
	
	for(int i = 0; i < n; i++){
		cin >> tempQueue >> tempScore;
		queue[tempQueue] += tempScore;
	}
	
	int maxIndex = 0;
	for(int i = 0; i < 100001; i++){
		if(queue[i] > queue[maxIndex]){
			maxIndex = i;
		}
	}
	
	cout << maxIndex << " " << queue[maxIndex] << endl;
	
	return 0;
}
