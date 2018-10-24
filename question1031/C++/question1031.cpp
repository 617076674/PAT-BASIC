#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isValidString(string s, int weights[], char checkCodes[]);

int main(){
	int weights[18] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
	char checkCodes[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
	int n;
	cin >> n;
	
	vector<string> wrongStrings;
	string tempString;
	
	for(int i = 0; i < n; i++){
		cin >> tempString;
		if(!isValidString(tempString, weights, checkCodes)){
			wrongStrings.push_back(tempString);
		}
	}
	
	if(wrongStrings.size() == 0){
		cout << "All passed" << endl;
	}else{
		for(int i = 0; i < wrongStrings.size(); i++){
			cout << wrongStrings[i] << endl;
		}
	}
	
	return 0;
}
 
bool isValidString(string s, int weights[], char checkCodes[]){
	int result = 0;
	for(int i = 0; i < 17; i++){
		result += (s[i] - '0') * weights[i];
	}
	if(s[17] == checkCodes[result % 11]){
		return true;
	}else{
		return false;
	}
} 
