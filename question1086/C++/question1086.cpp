#include<iostream>
#include<sstream>

using namespace std;

int main(){
	int A, B;
	scanf("%d %d", &A, &B);
	
	stringstream ss;
	ss << (A * B);
	
	string result;
	
	ss >> result;
	
	int i = result.length() - 1;
	while(result[i] == '0'){
		i--;
	}
	for(; i >= 0; i--){
		cout << result[i];
	}
	
	return 0;
}
