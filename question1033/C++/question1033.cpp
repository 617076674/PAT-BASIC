#include<iostream>

using namespace std;

int main() {
	string brokenString;
	string inputString;
	char c;
	
	getline(cin, brokenString);
	getline(cin, inputString);
	
	bool brokens[41];//Ë÷Òý0~25´æ´¢a-z£¬26~35´æ´¢Êý×Ö0~9£¬36´æ´¢_£¬37´æ´¢','£¬38´æ´¢'.'£¬39´æ´¢'-'£¬40´æ´¢'+' true±íÊ¾Î´Ëð»µ£¬false±íÊ¾Ëð»µ
	for(int i = 0; i < 41; i++) {
		brokens[i] = true;
	}

	for(int i = 0; i < brokenString.length(); i++) {
		if(brokenString[i] >= 'A' && brokenString[i] <= 'Z') {
			brokens[brokenString[i] - 'A'] = false;
		} else if(brokenString[i] >= '0' && brokenString[i] <= '9') {
			brokens[brokenString[i] - '0' + 26] = false;
		} else if(brokenString[i] == '_') {
			brokens[36] = false;
		} else if(brokenString[i] == ',') {
			brokens[37] = false;
		} else if(brokenString[i] == '.') {
			brokens[38] = false;
		} else if(brokenString[i] == '-') {
			brokens[39] = false;
		} else if(brokenString[i] == '+') {
			brokens[40] = false;
		}
	}
	string outputString = "";
	for(int i = 0; i < inputString.length(); i++) {
		if(inputString[i] >= 'a' && inputString[i] <= 'z' && brokens[inputString[i] - 'a']) {
			outputString += inputString[i];
		} else if(inputString[i] >= 'A' && inputString[i] <= 'Z' && brokens[inputString[i] - 'A'] && brokens[40]) {
			outputString += inputString[i];
		} else if(inputString[i] >= '0' && inputString[i] <= '9' && brokens[inputString[i] - '0' + 26]) {
			outputString += inputString[i];
		} else if(inputString[i] == '_' && brokens[36]) {
			outputString += inputString[i];
		} else if(inputString[i] == ',' && brokens[37]) {
			outputString += inputString[i];
		} else if(inputString[i] == '.' && brokens[38]) {
			outputString += inputString[i];
		} else if(inputString[i] == '-' && brokens[39]) {
			outputString += inputString[i];
		}
	}

	if(outputString.length() == 0) {
		printf("\n");
	} else {
		cout << outputString << endl;
	}

	return 0;
}
