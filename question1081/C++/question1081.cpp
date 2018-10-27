#include<iostream>
#include<string>

using namespace std;

bool containsIllegalChar(string s);
bool containsNum(string s);
bool containsLetter(string s);

int main(){
	int N;
	cin >> N;
	
	getchar();
	string password;
	
	for(int i = 0; i < N; i++){
		getline(cin, password);
		if(password.length() < 6){
			printf("Your password is tai duan le.\n");
		}else if(containsIllegalChar(password)){
			printf("Your password is tai luan le.\n");
		}else if(containsLetter(password) && !containsNum(password)){
			printf("Your password needs shu zi.\n");
		}else if(!containsLetter(password) && containsNum(password)){
			printf("Your password needs zi mu.\n");
		}else{
			printf("Your password is wan mei.\n");
		}
	}
	
	return 0;
}

bool containsIllegalChar(string s){
	for(int i = 0; i < s.length(); i++){
		if(!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z') && !(s[i] >= '0' && s[i] <= '9') && s[i] != '.'){
			return true;
		}
	}
	return false;
}

bool containsNum(string s){
	for(int i = 0; i < s.length(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			return true;
		}
	}
	return false;
}

bool containsLetter(string s){
	for(int i = 0; i < s.length(); i++){
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
			return true;
		}
	}
	return false;
}
