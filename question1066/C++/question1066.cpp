#include<iostream>

using namespace std;

int main(){
	int M, N, A, B, newColor;
	scanf("%d %d %d %d %d", &M, &N, &A, &B, &newColor);
	
	int tempColor;
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &tempColor);
			if(tempColor >= A && tempColor <= B){
				tempColor = newColor;
			}
			printf("%03d", tempColor);
			if(j != N - 1){
				printf(" ");
			}
		}
		printf("\n");
	}
}
