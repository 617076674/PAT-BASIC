#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	getchar();

	int flags[40];
	for(int i = 0; i < 40; i++) {
		flags[i] = 0;
	}

	char tempChar;
	int sum = 0;
	int count = 0;

	vector<int> friends;
	while((tempChar = getchar()) != '\n') {
		if(tempChar == ' ') {
			if(flags[sum] == 0) {
				flags[sum] = 1;
				count++;
				friends.push_back(sum);
			}
			sum = 0;
		} else {
			sum += (tempChar - '0');
		}
	}

	if(flags[sum] == 0) {
		flags[sum] = 1;
		count++;
		friends.push_back(sum);
	}

	cout << count << endl;

	sort(friends.begin(), friends.end());
	for(int i = 0; i < friends.size(); i++) {
		cout << friends[i];
		if(i != friends.size() - 1) {
			cout << " ";
		}
	}
}
