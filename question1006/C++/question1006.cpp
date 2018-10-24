#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	int num;
	cin >> num;
	
	vector<int> nums;
	while (num > 0) {
		nums.push_back(num % 10);
		num /= 10;
	}
	string result;
	string strings[] = { "1", "12", "123", "1234", "12345", "123456", "1234567", "12345678", "123456789" };
	if (nums.size() == 3) {
		while (nums[2] > 0) {
			nums[2]--;
			result += "B";
		}
		while (nums[1] > 0) {
			nums[1]--;
			result += "S";
		}
		if (nums[0] != 0) {
			result += strings[nums[0] - 1];
		}
	} else if (nums.size() == 2) {
		while (nums[1] > 0) {
			nums[1]--;
			result += "S";
		}
		if (nums[0] != 0) {
			result += strings[nums[0] - 1];
		}
	} else {
		if (nums[0] != 0) {
			result += strings[nums[0] - 1];
		}
	}
	cout << result;
}