#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	int m;
	cin >> n >> m;

	if (m >= n) {
		m %= n;
	}

	vector<int> array;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		array.push_back(temp);
	}

	vector<bool> flag;
	for (int i = 0; i < n; i++) {
		flag.push_back(false);
	}

	for (int i = 0; i < array.size(); i++) {
		if (flag[i]) {
			continue;
		}
		flag[i] = true;
		int temp = array[i];
		int index = i;
		while (true) {
			int next = index - m;
			if (next < 0) {
				next += n;
			}
			if (next == i) {
				array[index] = temp;
				break;
			}
			array[index] = array[next];
			flag[next] = true;
			index = next;
		}
	}
	
	for (int i = 0; i < array.size(); i++) {
		cout << array[i];
		if (i != array.size() - 1) {
			cout << " ";
		}
	}
}