#include<iostream>
#include<string>

using namespace std;

int changeToNum(string s);

int main(){
	int N;
	cin >> N;
	
	string input[N];
	
	string tempString;
	
	for(int i = 0; i < N; i++){
		cin >> tempString;
		input[i] = tempString;
	}
	
//	for(int i = 0; i < N; i++){
//		cout << input[i] << " ";
//	}
	
	int wolf1;
	int wolf2;
	
	int flags[N];
	int count;	
	for(wolf1 = 0; wolf1 < N; wolf1++){
		for(wolf2 = wolf1 + 1; wolf2 < N; wolf2++){
			count = 0;
			for(int i = 0; i < N; i++){
//				cout << "input = " << input[i] << " wolf1 = " << wolf1 << " wolf2 = " << wolf2 << " changeToNum(input[i]) = " << changeToNum(input[i]) << endl;		
				if(input[i][0] == '-'){
					if(changeToNum(input[i]) != wolf1 + 1 && changeToNum(input[i]) != wolf2 + 1){
						count++;
						flags[i] = 1;
					}else{
						flags[i] = 0;
					}
				}else if(input[i][0] == '+'){
					if(changeToNum(input[i]) == wolf1 + 1 || changeToNum(input[i]) == wolf2 + 1){
						count++;
						flags[i] = 1;
					}else{
						flags[i] = 0;
					}
				}
//				cout << "count = " << count << endl;
			}
			if(count == 2 && (flags[wolf1] + flags[wolf2] == 1)){
				printf("%d %d", wolf1 + 1, wolf2 + 1);
				return 0;
			}
		}
	}
	
	printf("No Solution");
	
	return 0;
}

int changeToNum(string s){
	int result = 0;
	for(int i = 1; i < s.length(); i++){
		result = result * 10 + s[i] - '0';
	}
	return result;
}
