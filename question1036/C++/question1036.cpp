#include<iostream>

using namespace std;

void printFirstAndLastLine(int col, char c);
void printOtherLine(int col, char c);

int main(){
	int col;
	char c;
	
	cin >> col >> c;
	
	int row = col / 2;
	if(col % 2 == 1){
		row++;
	}
	printFirstAndLastLine(col, c);
	printf("\n");
	for(int i = 0; i < row - 2; i++){
		printOtherLine(col, c);
		printf("\n"); 
	}
	printFirstAndLastLine(col, c);
	
}

void printFirstAndLastLine(int col, char c){
	for(int i = 0; i < col; i++){
		cout << c;
	}
}

void printOtherLine(int col, char c){
	cout << c;
	for(int i = 0; i < col - 2; i++){
		cout << " ";
	}
	cout << c;
}
