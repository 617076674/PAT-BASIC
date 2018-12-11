#include<iostream>
#include<vector>

using namespace std;

int main(){
	int N, M;
	scanf("%d %d", &N, &M); 
	int sales[N + 1];	//第i种月饼的销量为sales[i]
	fill(sales + 1, sales + N + 1, 0);
	for(int i = 0; i < M; i++){
		for(int j = 1; j <= N; j++){
			int num;
			scanf("%d", &num);
			sales[j] += num;
		}
	}
	int maxIndex = 1;
	for(int i = 2; i <= N; i++){
		if(sales[i] > sales[maxIndex]){
			maxIndex = i;
		}
	} 
	printf("%d\n", sales[maxIndex]);
	vector<int> result;
	for(int i = 1; i <= N; i++){
		if(sales[i] == sales[maxIndex]){
			result.push_back(i);
		}
	} 
	for(int i = 0; i < result.size(); i++){
		printf("%d", result[i]);
		if(i != result.size() - 1){
			printf(" ");
		}else{
			printf("\n");
		}
	}
	return 0;
}
