#include<iostream>
#include<vector>

using namespace std;

int main(){
	int N;
	cin >> N;
	
	int tempNum;
	vector<int> nums;
	
	for(int i = 0; i < N; i++){
		cin >> tempNum;
		nums.push_back(tempNum);
	}
	
	int sum = 0;
	for(int i = 0; i < N; i++){
		for(int j = i + 1; j < N; j++){
			sum += (nums[i] + nums[j]) * 11;
		}
	}
	
	cout << sum;
	return 0;
}
