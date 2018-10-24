#include<iostream>
#include<string>

using namespace std;

int calculateQueueNumber(string number);

int main(){
	int n;
	cin >> n;
	
	string number;
	int score;
	int total[1001];
	
	for(int i = 0; i < 1001; i++){
		total[i] = 0;
	}
	
	for(int i = 0; i < n; i++){
		cin >> number >> score;
		total[calculateQueueNumber(number)] += score;
	}
	
	int maxIndex = 0;
	for(int i = 1; i < 1001; i++){
		if(total[i] > total[maxIndex]){
			maxIndex = i;
		}
	}
	
	cout << maxIndex << " " << total[maxIndex] << endl;
	
	return 0;
}

int calculateQueueNumber(string number){
	int result = 0;
	for(int i = 0; i < number.length(); i++){
		if(number[i] == '-'){
			break;
		}
		result = result * 10 + (number[i] - '0');
	}
	return result;
}
