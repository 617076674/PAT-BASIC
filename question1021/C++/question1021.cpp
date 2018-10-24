#include<iostream>
#include<string>

using namespace std;

int main() {
	string input;
	cin >> input;
	int count[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < input.length(); i++) {
		for (int j = 0; j <= 9; j++) {
			if (input[i] - '0' == j) {
				count[j]++;
				break;
			}
		}
	}
	for (int i = 0; i <= 9; i++) {
		if (count[i] == 0) {
			continue;
		}
		cout << i << ":" << count[i] << endl;
	}
}