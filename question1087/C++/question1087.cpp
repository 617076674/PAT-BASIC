#include<iostream>

using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	
	int flags[15000];
	for(int i = 0; i < 15000; i++){
		flags[i] = 0;
	}
	
	int count = 0;
	int result;
	for(int i = 1; i <= N; i++){
		result = i / 2 + i / 3 + i / 5;
		if(flags[result] == 0){
			count++;
			flags[result]++;
		}
	}
	
	printf("%d", count);
	
	return 0;
}
