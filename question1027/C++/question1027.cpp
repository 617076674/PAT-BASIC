#include<iostream>
#include<vector>

using namespace std;

int main() {
	int count;
	char c;

	cin >> count >> c;

	int realCount = 1;
	int level = 1;
	while (true) {
		int nextRealCount = realCount + 2 * (1 + 2 * level);
		if (nextRealCount <= count) {
			realCount = nextRealCount;
		} else {
			break;
		}
		level++;
	}
	for (int i = level - 1; i >= 0; i--) {
		for (int j = 0; j < level - i - 1; j++) {
			cout << " ";
		}
		for (int j = 0; j < 1 + 2 * i; j++) {
			cout << c;
		}
		printf("\n");
	}
	for (int i = 1; i < level; i++) {
		for (int j = 0; j < level - i - 1; j++) {
			cout << " ";
		}
		for (int j = 0; j < 1 + 2 * i; j++) {
			cout << c;
		}
		printf("\n");
	}

	int remain = count - realCount;
	cout << remain;
}