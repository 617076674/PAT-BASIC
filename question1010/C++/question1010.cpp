#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	int num;
	vector<int> nums;

	while (true) {
		cin >> num;
		nums.push_back(num);

		if (getchar() == '\n') {
			break;
		}
	}

	for (int i = 0; i < nums.size(); i += 2) {
		int num1 = nums[i];
		int num2 = nums[i + 1];
		
		if (i == 0 && num2 == 0) {
			cout << "0 0";
			break;
		}
		
		if (num1 * num2 == 0) {
			continue;
		}
		if (i != 0) {
			cout << " ";
		}
		cout << num1 * num2 << " " << num2 - 1;
	}

}