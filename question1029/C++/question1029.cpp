#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	string input1;
	string input2;

	cin >> input1 >> input2;

	vector<char> broken;
	int index1 = 0;
	int index2 = 0;
	while (true) {
		if (index1 >= input1.length() && index2 >= input2.length()) {
			break;
		} else if (index1 < input1.length() && index2 >= input2.length()) {
			for (int i = index1; i < input1.length(); i++) {
				char c = input1[i];
				if (c >= 'a' && c <= 'z') {
					c = c - 'a' + 'A';
				}
				vector<char>::iterator it;
				it = find(broken.begin(), broken.end(), c);
				if (it == broken.end()) {
					broken.push_back(c);
				}
			}
			break;
		}else if (input1[index1] == input2[index2]) {
			index1++;
			index2++;
		} else if (input1[index1] != input2[index2]) {
			char c = input1[index1];
			if (c >= 'a' && c <= 'z') {
				c = c - 'a' + 'A';
			}
			vector<char>::iterator it;
			it = find(broken.begin(), broken.end(), c);
			if (it == broken.end()) {
				broken.push_back(c);
			}
			index1++;
		}
	}

	for (int i = 0; i < broken.size(); i++) {
		cout << broken[i];
	}
}