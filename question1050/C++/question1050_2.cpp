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
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			result[i][j] = 0;
		}
	}

	int index = 0;

	int top = 0;
	int bottom = m - 1;
	int left = 0;
	int right = n - 1;
	while(top <= bottom && left <= right){
		for(int i = left; i <= right; i++){
			result[top][i] = nums[index++];
		}
		top++;
		for(int i = top; i <= bottom; i++){
			result[i][right] = nums[index++];
		}
		right--;
		if(top <= bottom){
			for(int i = right; i >= left; i--){
				result[bottom][i] = nums[index++];
			}
			bottom--;
		}
		if(left <= right){
			for(int i = bottom; i >= top; i--){
				result[i][left] = nums[index++];
			}
			left++;
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

