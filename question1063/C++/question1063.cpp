#include<iostream>
#include<math.h>

using namespace std;

int main(){
	int N;
	cin >> N;
	
	long max = 0;
	long tempSquare;
	long tempNum1;
	long tempNum2;
	
	for(int i = 0; i < N; i++){
		cin >> tempNum1 >> tempNum2;
		tempSquare = tempNum1 * tempNum1 + tempNum2 * tempNum2;
		if(tempSquare > max){
			max = tempSquare;
		}
	}
	
	printf("%.2lf", sqrt(max));
	
	return 0;
}
