#include<iostream>
#include<cstring>

int main(){
	int M;
	scanf("%d", &M);
	for(int i = 0; i < M; i++){
		int num;
		scanf("%d", &num);
		char input[4];
		sprintf(input, "%d", num);
		int N = 1;
		for(; N < 10; N++){
			int result = num * num * N;
			char output[8];
			sprintf(output, "%d", result);
			bool flag = true;
			if(strlen(output) >= strlen(input)){
				for(int k = strlen(output) - strlen(input); k < strlen(output); k++){
					if(output[k] != input[k - (strlen(output) - strlen(input))]){
						flag = false;
						break;
					}
				}
			}else{
				flag = false;
			}
			if(flag){
				printf("%d %d\n", N, result);
				break;  
			}
		}
		if(N >= 10){
			printf("No\n");
		}
	}
} 
