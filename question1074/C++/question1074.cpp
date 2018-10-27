#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string reverseString(string s);

int main() {
	string input1;
	string input2;
	string input3;

	getline(cin, input1);
	getline(cin, input2);
	getline(cin, input3);

	string reverseInput1 = reverseString(input1);
	string reverseInput2 = reverseString(input2);
	string reverseInput3 = reverseString(input3);

	int index = 0;
	int flag = 0;
	string result = "";
	while(true) {
		if(index >= reverseInput2.length() && index >= reverseInput3.length()) {
			break;
		} else if(index < reverseInput2.length() && index >= reverseInput3.length()) {
			int sum = reverseInput2[index] + flag - '0';
			int system = reverseInput1[index] - '0';
			if(system == 0) {
				system = 10;
			}
			if(sum >= system) {
				flag = sum / system;
				int output = sum - system * flag;
				char outputChar = '0' + output;
				result = outputChar + result;
			} else {
				flag = 0;
				int output = sum;
				char outputChar = '0' + output;
				result = outputChar + result;
			}
		} else if(index >= reverseInput2.length() && index < reverseInput3.length()) {
			int sum = reverseInput3[index] + flag - '0';
			int system = reverseInput1[index] - '0';
			if(system == 0) {
				system = 10;
			}
			if(sum >= system) {
				flag = sum / system;
				int output = sum - system * flag;
				char outputChar = '0' + output;
				result = outputChar + result;
			} else {
				flag = 0;
				int output = sum;
				char outputChar = '0' + output;
				result = outputChar + result;
			}
		} else if(index < reverseInput2.length() && index < reverseInput3.length()) {
			int sum = reverseInput3[index] + flag - '0' + reverseInput2[index] - '0';
			int system = reverseInput1[index] - '0';
			if(system == 0) {
				system = 10;
			}
			if(sum >= system) {
				flag = sum / system;
				int output = sum - system * flag;
				char outputChar = '0' + output;
				result = outputChar + result;
			} else {
				flag = 0;
				int output = sum;
				char outputChar = '0' + output;
				result = outputChar + result;
			}
		}
		index++;
	}
	while(flag != 0 && index < reverseInput1.length()) {
		int sum = flag;
		int system = reverseInput1[index] - '0';
		if(system == 0) {
			system = 10;
		}
		if(sum >= system) {
			flag = sum / system;
			int output = sum - system * flag;
			char outputChar = '0' + output;
			result = outputChar + result;
		} else {
			flag = 0;
			int output = sum;
			char outputChar = '0' + output;
			result = outputChar + result;
		}
	}
	while(flag != 0){
		int sum = flag;
		int system = 10;
		if(sum >= system) {
			flag = sum / system;
			int output = sum - system * flag;
			char outputChar = '0' + output;
			result = outputChar + result;
		} else {
			flag = 0;
			int output = sum;
			char outputChar = '0' + output;
			result = outputChar + result;
		}
	}

	int i = 0;
	while(result[i] == '0'){
		i++;
		if(i == result.length()){
			cout << 0 << endl;
			return 0;
		}
	}
	for(int j = i; j < result.length(); j++){
		cout << result[j];
	}

	return 0;
}

string reverseString(string s) {
	string result = "";
	for(int i = s.length() - 1; i >= 0; i--) {
		result += s[i];
	}
	return result;
}
