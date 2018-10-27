#include<iostream>
#include<math.h>

using namespace std;

int main(){
	int N;
	cin >> N;
	
	int diff[10000];
	for(int i = 0; i < 10000; i++){
		diff[i] = 0;
	}
	
	int tempNum;
	for(int i = 1; i <= N; i++){
		cin >> tempNum;
		diff[abs(tempNum - i)]++;
	}
	
	for(int i = 9999; i >= 0; i--){
		if(diff[i] > 1){
			printf("%d %d\n", i, diff[i]);
		}
	}
	
	return 0;
}
