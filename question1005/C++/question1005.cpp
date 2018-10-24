#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> addToOverrideNums(int num, vector<int> overrideNums);
bool compareNum(int num1, int num2);

int main() {
	int count;
	cin >> count;

	vector<int> inputNums;
	vector<int> overrideNums;
	vector<int> result;
	
	for (int i = 0; i < count; i++) {
		int num;
		cin >> num;
		inputNums.push_back(num);
		overrideNums = addToOverrideNums(num, overrideNums);
	}

	for (int i = 0; i < inputNums.size(); i++) {
		if (std::find(overrideNums.begin(), overrideNums.end(), inputNums[i]) != overrideNums.end()) {
			continue;
		}
		result.push_back(inputNums[i]);
	}
	sort(result.begin(), result.end(), compareNum);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
		if (i != result.size() - 1) {
			cout << " ";
		}
	}
}

vector<int> addToOverrideNums(int num, vector<int> overrideNums) {
	while (num > 1) {
		if (num % 2 == 0) {
			num /= 2;
		} else {
			num = (3 * num + 1) / 2;
		}
		if (num != 1) {
			overrideNums.push_back(num);
		}
	}
	return overrideNums;
}

bool compareNum(int num1, int num2) {
	if (num1 > num2) {
		return true;
	} else {
		return false;
	}
}