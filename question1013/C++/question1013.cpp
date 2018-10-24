#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

bool isPrime(int num);

int main() {
	int m;
	int n;
	cin >> m >> n;

	int count = 1;
	vector<int> primes;
	for (int i = 2; ; i++) {
		if (isPrime(i)) {
			if (count >= m) {
				primes.push_back(i);
			}
			if (count >= n) {
				break;
			}
			count++;
		}
	}

	for (int i = 0; i < primes.size(); i++) {
		if ((i + 1) % 10 == 0) {
			printf("%d\n", primes[i]);
		} else {
			if (i == primes.size() - 1) {
				printf("%d", primes[i]);
			} else {
				printf("%d ", primes[i]);
			}
		}
	}
}

bool isPrime(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}