#include<iostream>
#include<vector>

using namespace std;

int main(){
	long n;
	cin >> n;
	
	vector<double> nums;
	double tempNum;
	
	for(int i = 0; i < n; i++){
		cin >> tempNum;
		nums.push_back(tempNum);
	}
	
	long count[n];
	for(int i = 0; i < n; i++){
		count[i] = (n - i) * (i + 1);
	}

	
	double result = 0.0;
	for(int i = 0; i < n; i++){
		result += count[i] * nums[i];
	}
	
	printf("%.2f", result);
	
	return 0;
}
