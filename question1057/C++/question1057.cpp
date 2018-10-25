#include<iostream>
#include<string>

using namespace std;

int main() {
	string input;

	getline(cin, input);

	long N = 0;
	for(int i = 0; i < input.length(); i++) {
		if(input[i] >= 'a' && input[i] <= 'z') {
			N += (input[i] - 'a') + 1;
		} else if(input[i] >= 'A' && input[i] <= 'Z') {
			N += (input[i] - 'A') + 1;
		}
	}

	int count0 = 0;
	int count1 = 0;
	while(N > 0) {
		//���Ե�2��0 
		if(N % 2 == 0) {
			count0++;
		} else {
			count1++;
		}
		N /= 2;
	}
	cout << count0 << " " << count1 << endl;

	return 0;
}
