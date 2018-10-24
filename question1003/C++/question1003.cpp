#include<iostream>
#include<string>

using namespace std;

bool conditionFirst(string s);
bool conditionSecond(string s);
bool conditionThird(string s);
bool condition(string s);

int main() {
	int count;
	cin >> count;
	string input;

	for (int i = 0; i < count; i++) {
		cin >> input;
		bool result = condition(input);
		if (result) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}

bool onlyContainA(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != 'A') {
			return false;
		}
	}
	return true;
}

bool conditionFirst(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != 'P' && s[i] != 'A' && s[i] != 'T') {
			return false;
		}
	}
	return true;
}

bool conditionSecond(string s) {
	int indexP = -1;
	for (int i = 0; i < s.length() - 2; i++) {
		if (s[i] == 'P' && s[i + 1] == 'A' && s[i + 2] == 'T') {
			indexP = i;
			break;
		}
	}
	if (indexP == -1) {
		return false;
	}
	string x1 = s.substr(0, indexP);
	if (!onlyContainA(x1)) {
		return false;
	}
	string x2 = s.substr(indexP + 3, s.length() - (indexP + 3));
	if (x1.compare(x2) == 0) {
		return true;
	} else {
		return false;
	}
}

bool conditionThird(string s) {
	int indexP = -1;
	for (int i = 0; i < s.length() - 2; i++) {
		if (s[i] == 'P') {
			indexP = i;
			break;
		}
	}
	if (indexP == -1) {
		return false;
	}
	int indexT = -1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == 'T') {
			indexT = i;
			break;
		}
	}
	if (indexT == -1) {
		return false;
	}
	if (s[indexT - 1] != 'A') {
		return false;
	}
	string a = s.substr(0, indexP);
	string b = s.substr(indexP + 1, indexT - 2 - indexP);
	string ca = s.substr(indexT + 1, s.length() - 1 - indexT);
	if (!onlyContainA(a) || !onlyContainA(b) || !onlyContainA(ca)) {
		return false;
	}
	if (ca.length() < a.length()) {
		return false;
	}
	string c = ca.substr(0, ca.length() - a.length());
	string newS = a + "P" + b + "T" + c;
	return condition(newS);
}

bool condition(string s) {
	if (conditionFirst(s)) {
		if (conditionSecond(s)) {
			return true;
		} else {
			if (conditionThird(s)) {
				return true;
			} else {
				return false;
			}
		}
	} else {
		return false;
	}
}

