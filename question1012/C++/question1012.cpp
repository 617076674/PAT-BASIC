#include<iostream>
#include<vector>

using namespace std;

int main() {
	int count;
	cin >> count;
	int temp;
	vector<int> nums;

	for (int i = 0; i < count; i++) {
		cin >> temp;
		nums.push_back(temp);
	}

	vector<int> a1;
	vector<int> a2;
	vector<int> a3;
	vector<int> a4;
	vector<int> a5;


	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] % 2 == 0 && nums[i] % 5 == 0) {
			a1.push_back(nums[i]);
		}
		if (nums[i] % 5 == 1) {
			a2.push_back(nums[i]);
		}
		if (nums[i] % 5 == 2) {
			a3.push_back(nums[i]);
		}
		if (nums[i] % 5 == 3) {
			a4.push_back(nums[i]);
		}
		if (nums[i] % 5 == 4) {
			a5.push_back(nums[i]);
		}
	}

	if (a1.size() == 0) {
		cout << "N ";
	} else {
		int sum = 0;
		for (int i = 0; i < a1.size(); i++) {
			sum += a1[i];
		}
		cout << sum << " ";
	}

	if (a2.size() == 0) {
		cout << "N ";
	} else {
		int sum = 0;
		for (int i = 0; i < a2.size(); i++) {
			if (i % 2 == 0) {
				sum += a2[i];
			} else {
				sum -= a2[i];
			}
		}
		cout << sum << " ";
	}

	if (a3.size() == 0) {
		cout << "N ";
	} else {
		int sum = a3.size();
		cout << sum << " ";
	}

	if (a4.size() == 0) {
		cout << "N ";
	} else {
		int sum = 0;
		for (int i = 0; i < a4.size(); i++) {
			sum += a4[i];
		}
		double average = 1.0 * sum / a4.size();
		printf("%.1f ", average);
	}

	if (a5.size() == 0) {
		cout << "N";
	} else {
		int max = a5[0];
		for (int i = 1; i < a5.size(); i++) {
			if (a5[i] > max) {
				max = a5[i];
			}
		}
		cout << max;
	}
}