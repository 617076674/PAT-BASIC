#include<iostream>
#include<string>

using namespace std;

int main() {
	string input;
	getline(cin, input);

	int count[6];//count[0]统计P的数量，count[1]统计A的数量，count[2]统计T的数量，count[3]统计e的数量，count[4]统计s的数量，count[5]统计t的数量
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
