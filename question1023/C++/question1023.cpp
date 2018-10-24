#include<iostream>
#include<vector>

using namespace std;

void swap(vector<int>& nums, int i, int j);
void printNums(vector<int> nums);

int main() {
	int temp;
	vector<int> nums;
	vector<int> digits;

	while (true) {
		cin >> temp;
		nums.push_back(temp);

		if (getchar() == '\n') {
			break;
		}
	}
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums[i]; j++) {
			digits.push_back(i);
		}
	}

	if (digits[0] == 0) {
		int index = -1;
		for (int i = 0; i < digits.size(); i++) {
			if (digits[i] != 0) {
				index = i;
				break;
			}
		}
		swap(digits, 0, index);
	}
	printNums(digits);
}

void swap(vector<int>& nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

void printNums(vector<int> nums) {
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i];
	}
}