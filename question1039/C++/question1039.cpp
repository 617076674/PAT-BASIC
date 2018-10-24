#include<iostream>
#include<string>

using namespace std;

void countChar(int *p, string s);

int main(){
	string input1;
	string input2;
	
	getline(cin, input1);
	getline(cin, input2);
	
	int counts1[62];//0~9存储字符'0'~'9'的数量，10~35存储'a'~'z'的数量，36~61存储'A'~'Z'的数量 
	int counts2[62];
	for(int i = 0; i < 62; i++){
		counts1[i] = 0;
		counts2[i] = 0;
	}
	
	countChar(counts1, input1);
	countChar(counts2, input2);
	
	int countsDiff[62];
	for(int i = 0; i < 62; i++){
		countsDiff[i] = counts1[i] - counts2[i];
	}
	
	int lackCount = 0;
	for(int i = 0; i < 62; i++){
		if(countsDiff[i] < 0){
			lackCount -= countsDiff[i];
		}
	}
	
	if(lackCount == 0){
		printf("Yes %d", input1.length() - input2.length());
	}else{
		printf("No %d", lackCount);
	}
	
	return 0;
}

void countChar(int *p, string s){
	char tempChar;
	for(int i = 0; i < s.length(); i++){
		tempChar = s[i];
		if(tempChar >= '0' && tempChar <= '9'){
			p[tempChar - '0']++;
		}else if(tempChar >= 'a' && tempChar <= 'z'){
			p[tempChar - 'a' + 10]++;
		}else if(tempChar >= 'A' && tempChar <= 'Z'){
			p[tempChar - 'A' + 36]++;
		}
	}
}
