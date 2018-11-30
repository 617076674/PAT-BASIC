#include<iostream>
#include<cmath>

using namespace std;

int ranks[10000];
bool flag[10001];

bool isPrime(int num);
void findPrime();

int main() {
	fill(ranks, ranks + 10000, 0);
	fill(flag, flag + 10001, true);
	findPrime(); 
	int N;
	scanf("%d", &N);
	int num;
	for(int i = 1; i <= N; i++) {
		scanf("%d", &num);
		ranks[num] = i;
	}
	int K;
	scanf("%d", &K);
	for(int i = 0; i < K; i++) {
		scanf("%d", &num);
		printf("%04d: ", num);
		if(ranks[num] == -1){
			printf("Checked\n");
		}else if(ranks[num] == 1) {
			printf("Mystery Award\n");
			ranks[num] = -1;
		} else if(ranks[num] == 0) {
			printf("Are you kidding?\n");
		} else if(isPrime(ranks[num])) {
			printf("Minion\n");
			ranks[num] = -1;
		} else {
			printf("Chocolate\n");
			ranks[num] = -1;
		}
	}
	return 0;
}

bool isPrime(int num) {
//	if(num == 1) {
//		return false;
//	}
//	for(int i = 2; i <= sqrt(num); i++) {
//		if(num % i == 0) {
//			return false;
//		}
//	}
	return flag[num];
}

void findPrime(){
	flag[1] = false;
	flag[2] = false;
	for(int i = 2; i < 10001; i++){
		if(!flag[i]){
			for(int j = i + 1; j < 10001; j += i){
				flag[j] = false;
			}
		}
	}
}
