#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	string strings[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

	string n;
	cin >> n;

	int sum = 0;
	for (int i = 0; i < n.length(); i++) {
		sum += n[i] - '0';
	}
	vector<int> temp;
	while (sum > 0) {
		temp.push_back(sum % 10);
		sum /= 10;
	}
	for (int i = temp.size() - 1; i >= 0; i--) {
		cout << strings[temp[i]];
		if (i != 0) {
			cout << " ";
		}
	}
	
}