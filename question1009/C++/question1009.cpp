#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	string temp;
	vector<string> strings;
	
	while (true) {
		cin >> temp;
		strings.push_back(temp);
		if (getchar() == '\n') {
			break;
		}
	}

	for (int i = strings.size() - 1; i >= 0; i--) {
		cout << strings[i];
		if (i != 0) {
			cout << " ";
		}
	}
}