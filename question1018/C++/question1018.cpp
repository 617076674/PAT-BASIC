#include<iostream>

using namespace std;

int main() {
	int count;
	cin >> count;
	int win1 = 0;
	int tie1 = 0;
	int lose1 = 0;
	int win2 = 0;
	int tie2 = 0;
	int lose2 = 0;

	int win1C = 0;
	int win1J = 0;
	int win1B = 0;

	int win2C = 0;
	int win2J = 0;
	int win2B = 0;
	for (int i = 0; i < count; i++) {
		char letter1;
		char letter2;
		cin >> letter1 >> letter2;
		if (letter1 == 'C') {
			if (letter2 == 'C') {
				tie1++;
				tie2++;
			} else if (letter2 == 'J') {
				win1++;
				lose2++;
				win1C++;
			} else if (letter2 == 'B') {
				lose1++;
				win2++;
				win2B++;
			}
		} else if (letter1 == 'J') {
			if (letter2 == 'C') {
				lose1++;
				win2++;
				win2C++;
			} else if (letter2 == 'J') {
				tie1++;
				tie2++;
			} else if (letter2 == 'B') {
				win1++;
				lose2++;
				win1J++;
			}
		} else if (letter1 == 'B') {
			if (letter2 == 'C') {
				win1++;
				lose2++;
				win1B++;
			} else if (letter2 == 'J') {
				lose1++;
				win2++;
				win2J++;
			} else if (letter2 == 'B') {
				tie1++;
				tie2++;
			}
		}
	}
	cout << win1 << " " << tie1 << " " << lose1 << endl;
	cout << win2 << " " << tie2 << " " << lose2 << endl;

	if (win1B > win1C) {
		if (win1J > win1B) {
			cout << "J ";
		} else if (win1J == win1B) {
			cout << "B ";
		} else if (win1J < win1B) {
			cout << "B ";
		}
	} else if (win1B == win1C) {
		if (win1J > win1B) {
			cout << "J ";
		} else if (win1J == win1B) {
			cout << "B ";
		} else if (win1J < win1B) {
			cout << "B ";
		}
	} else if (win1B < win1C) {
		if (win1J > win1C) {
			cout << "J ";
		} else if (win1J == win1C) {
			cout << "C ";
		} else if (win1J < win1C) {
			cout << "C ";
		}
	}

	if (win2B > win2C) {
		if (win2J > win2B) {
			cout << "J";
		} else if (win2J == win2B) {
			cout << "B";
		} else if (win2J < win2B) {
			cout << "B";
		}
	} else if (win2B == win2C) {
		if (win2J > win2B) {
			cout << "J";
		} else if (win2J == win2B) {
			cout << "B";
		} else if (win2J < win2B) {
			cout << "B";
		}
	} else if (win2B < win2C) {
		if (win2J > win2C) {
			cout << "J";
		} else if (win2J == win2C) {
			cout << "C";
		} else if (win2J < win2C) {
			cout << "C";
		}
	}

	system("pause");
	return 0;
}