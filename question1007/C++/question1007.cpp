#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

bool isPrime(int num);

int main() {
	int n;
	cin >> n;

	vector<int> primes;
	int count = 0;

	for (int i = 2; i <= n; i++) {
		if (isPrime(i)) {
			if (primes.size() != 0 && primes[primes.size() - 1] == i - 2) {
				count++;
			}
			primes.push_back(i);
		}
	}
	cout << count;
}

bool isPrime(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}