#include<iostream>
#include<string>
#include<vector>

using namespace std;

int calculateIndexSlide(string s);
long calculateNumerator(string s);
long calculateDenominator(string s);
long gcd(long num1, long num2);

int main(){
	
	string input1;
	string input2;
	cin >> input1 >> input2;
	
	long N1 = calculateNumerator(input1);
	long M1 = calculateDenominator(input1);
	long N2 = calculateNumerator(input2);
	long M2 = calculateDenominator(input2);
	
	long K;
	cin >> K;
	
	long minNumerator = K * M2 * N1;
	long maxNumerator = K * M1 * N2;
	if(minNumerator > maxNumerator){
		long temp = minNumerator;
		minNumerator = maxNumerator;
		maxNumerator = temp;
	}
	
	vector<int> numerators;
	for(long i = 1;; i++){
		if(M1 * M2 * i >= maxNumerator){
			break;
		}
		if(gcd(K, i) == 1 && M1 * M2 * i > minNumerator){
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

long calculateNumerator(string s){
	int indexSlide = calculateIndexSlide(s);
	long N = 0;
	for(int i = 0; i < indexSlide; i++){
		N = N * 10 + (s[i] - '0');
	}
	return N;
}

long calculateDenominator(string s){
	int indexSlide = calculateIndexSlide(s);
	long M = 0;
	for(int i = indexSlide + 1; i < s.length(); i++){
		M = M * 10 + (s[i] - '0');
	}
	return M;
}

long gcd(long num1, long num2){
	if(num2 == 0){
		return num1;
	}
	return gcd(num2, num1 % num2);
}


