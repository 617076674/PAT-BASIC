#include<iostream>

using namespace std;

int main() {
	int K, n1, b, n2;
	long T, t;
	cin >> T >> K;

	long total = T;
	for(int i = 0; i < K; i++) {
		if(total == 0) {
			printf("Game Over.\n");
			break;
		}

		cin >> n1 >> b >> t >> n2;
		if(t > total) {
			printf("Not enough tokens.  Total = %ld.\n", total);
		} else if((b == 0 && n2 < n1) || (b == 1 && n2 > n1)) {
			total += t;
			printf("Win %ld!  Total = %ld.\n", t, total);
		} else if((b == 0 && n2 > n1) || (b == 1 && n2 < n1)) {
			total -= t;
			printf("Lose %ld.  Total = %ld.\n", t, total);
		}
	}

	return 0;
}
