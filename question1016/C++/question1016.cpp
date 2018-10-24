#include<iostream>
#include<string>

using namespace std;

int main() {
	string input1;
	char num1;
	string input2;
	char num2;
	cin >> input1 >> num1 >> input2 >> num2;

	int count1 = 0;
	for (int i = 0; i < input1.length(); i++) {
		if (input1[i] == num1) {
			count1++;
		}
	}

	int count2 = 0;
	for (int i = 0; i < input2.length(); i++) {
		if (input2[i] == num2) {
			count2++;
		}
	}

	long pa = 0;
	while (count1 > 0) {
		pa = pa * 10 + num1 - '0';
		count1--;
	}

	long pb = 0;
	while (count2 > 0) {
		pb = pb * 10 + num2 - '0';
		count2--;
	}

	cout << (pa + pb);

	return 0;
}