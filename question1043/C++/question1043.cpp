#include<iostream>
#include<string>

using namespace std;

int main() {
	string input;
	getline(cin, input);

	int count[6];//count[0]ͳ��P��������count[1]ͳ��A��������count[2]ͳ��T��������count[3]ͳ��e��������count[4]ͳ��s��������count[5]ͳ��t������
	for (int i = 0; i < 6; i++) {
		count[i] = 0;
	}

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == 'P') {
			count[0]++;
		} else if (input[i] == 'A') {
			count[1]++;
		} else if (input[i] == 'T') {
			count[2]++;
		} else if (input[i] == 'e') {
			count[3]++;
		} else if (input[i] == 's') {
			count[4]++;
		} else if (input[i] == 't') {
			count[5]++;
		}
	}
	
	int maxIndex = 0;
	for(int i = 1; i < 6; i++){
		if(count[i] > count[maxIndex]){
			maxIndex = i;
		}
	}
	int maxCount = count[maxIndex];
	for(int i = 0; i < maxCount; i++){
		if (count[0]-- > 0) {
			cout << "P";
		}
		if (count[1]-- > 0) {
			cout << "A";
		}
		if (count[2]-- > 0) {
			cout << "T";
		}
		if (count[3]-- > 0) {
			cout << "e";
		}
		if (count[4]-- > 0) {
			cout << "s";
		}
		if (count[5]-- > 0) {
			cout << "t";
		}
	}

}
