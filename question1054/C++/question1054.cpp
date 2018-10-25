#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isValidInput(string s);
double changeToNums(string s);

int main() {
	int count;
	cin >> count;

	string tempString;
	vector<double> nums;
	for(int i = 0; i < count; i++) {
		cin >> tempString;
		if(isValidInput(tempString)) {
			nums.push_back(changeToNums(tempString));
		} else {
			cout << "ERROR: " << tempString << " is not a legal number" << endl;
		}
	}

	if(nums.size() == 0) {
		cout << "The average of 0 numbers is Undefined";
	} else if(nums.size() == 1){
		printf("The average of 1 number is %.2lf", nums[0]);
	}else{
		double sum = 0.0;
		for(int i = 0; i < nums.size(); i++) {
			sum += nums[i];
		}
		double average = sum / nums.size();
		printf("The average of %d numbers is %.2lf", nums.size(), average);
	}
}

bool isValidInput(string s) {
	if(s[0] == '-') {
		int countPoint = 0;
		int indexPoint = -1;
		for(int i = 1; i < s.length(); i++) {
			if(s[i] == '.') {
//				if we judge "3." is false, we can not be accepted by test 3. 
//				if(i == s.length() - 1){
//					return false;
//				}
				countPoint++;
				indexPoint = i;
			}
			if(!(s[i] >= '0' && s[i] <= '9') && s[i] != '.') {
				return false;
			}
		}
		if(indexPoint != -1 && indexPoint + 2 < s.length() - 1){
			return false;
		}
		if(countPoint >= 2) {
			return false;
		}
		double num = changeToNums(s);
		if(num <= 1000 && num >= -1000){
			return true;
		}else{
			return false;
		}
	}else {
		int countPoint = 0;
		int indexPoint = -1;
		for(int i = 0; i < s.length(); i++) {
			if(s[i] == '.') {
//				if we judge "3." is false, we can not be accepted by test 3. 
//				if(i == s.length() - 1){
//					return false;
//				}
				countPoint++;
				indexPoint = i;
			}
			if(!(s[i] >= '0' && s[i] <= '9') && s[i] != '.') {
				return false;
			}
		}
		if(indexPoint != -1 && indexPoint + 2 < s.length() - 1){
			return false;
		}
		if(countPoint >= 2) {
			return false;
		}
		double num = changeToNums(s);
		if(num <= 1000 && num >= -1000){
			return true;
		}else{
			return false;
		}
	}
}

double changeToNums(string s) {
	int indexPoint = -1;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '.'){
			indexPoint = i;
			break;
		}
	}
	if(s[0] == '-'){
		if(indexPoint == -1){
			double result = 0.0;
			for(int i = 1; i < s.length(); i++){
				result = result * 10 + (s[i] - '0');
			}
			return -result;
		}else{
			double result = 0.0;
			for(int i = 1; i < s.length(); i++){
				if(s[i] == '.'){
					continue;
				}
				result = result * 10 + (s[i] - '0');
			}
			for(int i = indexPoint + 1; i < s.length(); i++){
				result /= 10;
			}
			return -result;
		}
	}else{
		if(indexPoint == -1){
			double result = 0.0;
			for(int i = 0; i < s.length(); i++){
				result = result * 10 + (s[i] - '0');
			}
			return result;
		}else{
			double result = 0.0;
			for(int i = 0; i < s.length(); i++){
				if(s[i] == '.'){
					continue;
				}
				result = result * 10 + (s[i] - '0');
			}
			for(int i = indexPoint + 1; i < s.length(); i++){
				result /= 10;
			}
			return result;
		}
	}
}
