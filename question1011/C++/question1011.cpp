#include<iostream>

using namespace std;

int main() {
	int count;
	cin >> count;
	long num1 = 0;
	long num2 = 0;
	long num3 = 0;

	for (int i = 1; i <= count; i++) {
		cin >> num1 >> num2 >> num3;
		if (num1 + num2 > num3) {
			cout << "Case #" << i << ": " << "true" << endl;
		} else {
			cout << "Case #" << i << ": " << "false" << endl;
		}
	}
}