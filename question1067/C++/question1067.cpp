#include<iostream>
#include<string>

using namespace std;

int main(){
	string password;
	int N;
	cin >> password >> N;
	
	getchar();
	string tempPassword;
	while(true){
		if(N-- == 0){
			cout << "Account locked" << endl;
			break;
		}
		getline(cin, tempPassword);
		if(tempPassword.compare("#") == 0){
			break;
		}else if(tempPassword.compare(password) == 0){
			cout << "Welcome in" << endl;
			break;
		}else {
			cout << "Wrong password: " << tempPassword << endl;
		}
	}
	
	return 0;
}
