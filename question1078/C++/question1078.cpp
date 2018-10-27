#include<iostream>
#include<string>

using namespace std;

int main(){
	string input1;
	string input2;
	
	getline(cin, input1);
	getline(cin, input2);
	
	int count;
	if(input1.compare("C") == 0){
		for(int i = 0; i < input2.length(); i++){
			count = 1;
			while(input2[i + 1] == input2[i]){
				i++;
				count++;
			}
			if(count > 1){
				cout << count << input2[i];
			}else{
				cout << input2[i];
			}
		}
	}else if(input1.compare("D") == 0){
		for(int i = 0; i < input2.length(); i++){
			count = 0;
			while(input2[i] >= '0' && input2[i] <= '9'){
				count = count * 10 + input2[i] - '0';
				i++;
			}
//			cout << "count = " << count << endl;
			if(count == 0){
				cout << input2[i];
			}else{
				for(int j = 0; j < count; j++){
					cout << input2[i];
				}
			}
		}
	}
}
