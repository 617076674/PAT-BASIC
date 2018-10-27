#include<iostream>
#include<string>
#include<vector>

using namespace std;

int calculateIndexSlide(string s);
int calculateNumerator(string s);
int calculateDenominator(string s);
int gcd(int num1, int num2);

int main(){
	
	string input1;
	string input2;
	cin >> input1 >> input2;
	
	int N1 = calculateNumerator(input1);
	int M1 = calculateDenominator(input1);
	int N2 = calculateNumerator(input2);
	int M2 = calculateDenominator(input2);
	
	int K;
	cin >> K;
	
	double min = 1.0 * N1 / M1;
	double max = 1.0 * N2 / M2;
	if(min > max){
		double temp = min;
		min = max;
		max = temp;
	}

	vector<int> numerators;
	for(int i = 1;; i++){
		if(1.0 * i / K >= max){
			break;
		}
		if(gcd(K, i) == 1 && 1.0 * i / K > min){
			numerators.push_back(i);
		}
	}
	
	for(int i = 0; i < numerators.size(); i++){
		cout << numerators[i] << "/" << K;
		if(i != numerators.size() - 1){
			cout << " ";
		}
	}

	return 0;
}

int calculateIndexSlide(string s){
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '/'){
			return i;
		}
	}
	return -1;
}

int calculateNumerator(string s){
	int indexSlide = calculateIndexSlide(s);
	int N = 0;
	for(int i = 0; i < indexSlide; i++){
		N = N * 10 + (s[i] - '0');
	}
	return N;
}

int calculateDenominator(string s){
	int indexSlide = calculateIndexSlide(s);
	int M = 0;
	for(int i = indexSlide + 1; i < s.length(); i++){
		M = M * 10 + (s[i] - '0');
	}
	return M;
}

int gcd(int num1, int num2){

	if(num2 == 0){
		return num1;
	}
	return gcd(num2, num1 % num2);
}


