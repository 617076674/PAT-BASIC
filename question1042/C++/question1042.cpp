#include<iostream>
#include<string>

using namespace std;

int main() {
	string input;
	getline(cin, input);

	int count[26];

	for (int i = 0; i < 26; i++) {
		count[i] = 0;
	}

	for (int i = 0; i < input.length(); i++) {
		if (input[i] >= 'a' && input[i] <= 'z') {
			count[input[i] - 'a']++;
		}else if (input[i] >= 'A' && input[i] <= 'Z') {
			count[input[i] - 'A']++;
		}
	}

	int maxIndex = 0;
	for (int i = 1; i < 26; i++) {
		if (count[i] > count[maxIndex]) {
			maxIndex = i;
		}
	}

	char resultChar;
	resultChar = 'a' + maxIndex;

	cout << resultChar << " " << count[maxIndex];
}