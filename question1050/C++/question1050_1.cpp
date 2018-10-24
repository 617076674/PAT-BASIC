#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int compare(int num1, int num2);
void printMatrix(int *p, int m, int n);

int main() {
	int N;
	cin >> N;

	int m = N;
	int n = 1;

	for(int i = N - 1; i > 1; i--) {
		if(N % i == 0) {
			if(i - N / i >= 0 && i - N / i < m - n) {
				m = i;
				n = N / i;
			}
		}
	}

	vector<int> nums;
	int tempNum;

	for(int i = 0; i < N; i++) {
		cin >> tempNum;
		nums.push_back(tempNum);
	}

	sort(nums.begin(), nums.end(), compare);

	int result[m][n];

	int index = 0;

	int turns;
	int min = m;
	if(n < min){
		min = n;
	}
	if(min % 2 == 0){
		turns = min / 2 - 1;
	}else{
		turns = min / 2;
	}


	for(int k = 0; k <= turns; k++) {
		if(index < nums.size()){
		
		for(int i = k; i < n - k; i++) {
			result[k][i] = nums[index++];
			if(index >= nums.size()){
				break;
			}
		}
	}
	if(index < nums.size()){
		for(int i = 1 + k; i < m - k; i++) {
			result[i][n - 1 - k] = nums[index++];
			if(index >= nums.size()){
				break;
			}
		}
	}
	if(index < nums.size()){
		for(int i = n - 2 - k; i >= k; i--) {
			result[m - 1 - k][i] = nums[index++];
			if(index >= nums.size()){
				break;
			}
		}
	}
	if(index < nums.size()){
		for(int i = m - 2 - k; i > k; i--) {
			result[i][k] = nums[index++];
			if(index >= nums.size()){
				break;
			}
		}
	}
	}

	printMatrix((int *)result, m, n);

	return 0;
}

int compare(int num1, int num2) {
	if(num1 >= num2) {
		return 1;
	} else {
		return 0;
	}
}

void printMatrix(int *p, int m, int n){
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cout << *(p + i * n + j);
			if(j != n - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}
}
