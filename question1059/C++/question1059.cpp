#include<iostream>
#include<string>
#include<math.h>

using namespace std;

bool isPrime(int num);

int main() {
	int N;
	cin >> N;

	string prizes[10000];
	bool flags[10000];
	for(int i = 0; i < 10000; i++) {
		flags[i] = false;
	}
	int tempNum;

	for(int i = 0; i < N; i++) {
		cin >> tempNum;
		if(i == 0) {
			prizes[tempNum] = "Mystery Award";
		} else if(isPrime(i + 1)) {
			prizes[tempNum] = "Minion";
		} else {
			prizes[tempNum] = "Chocolate";
		}
	}

	int K;
	cin >> K;
	for(int i = 0; i < K; i++) {
		cin >> tempNum;
		if(!flags[tempNum]) {
			if(prizes[tempNum].length() != 0) {
				printf("%04d: ", tempNum);
				cout << prizes[tempNum] << endl;
				flags[tempNum] = true;
			}else{
				printf("%04d: ", tempNum);
				cout << "Are you kidding?" << endl;
			}
		} else {
			if(prizes[tempNum].length() != 0) {
				printf("%04d: ", tempNum);
				cout << "Checked" << endl;
			}else{
				printf("%04d: ", tempNum);
				cout << "Are you kidding?" << endl;
			}
		}
	}

	return 0;
}

bool isPrime(int num) {
	if(num == 1) {
		return false;
	}
	for(int i = 2; i <= sqrt(num); i++) {
		if(num % i == 0) {
			return false;
		}
	}
	return true;
}
