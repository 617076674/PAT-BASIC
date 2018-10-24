#include<iostream>
#include<vector>

using namespace std;

int main() {
	int num1;
	int num2;
	int d;
	cin >> num1 >> num2 >> d;

	int sum = num1 + num2;
	vector<int> nums;
	if (sum == 0) {
		cout << 0;
		return 0;
	}
	while (sum > 0) {
		nums.push_back(sum % d);
		sum /= d;
	}

	for (int i = nums.size() - 1; i >= 0; i--) {
		cout << nums[i];
	}
}