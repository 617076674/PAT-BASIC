#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int M, N, S;
	cin >> M >> N >> S;
	getchar();
	vector<string> winners;

	string tempName;
	string totalNames[M];
	for(int i = 0; i < M; i++) {
		getline(cin, tempName);
		totalNames[i] = tempName;
	}

	if(S - 1 >= M) {
		cout << "Keep going..." << endl;
		return 0;
	}
	int i = S - 1;
	while(i < M) {
		while(find(winners.begin(), winners.end(), totalNames[i]) != winners.end()) {
			i++;
			if(i >= M) {
				break;
			}
		}
		if(i < M) {
			winners.push_back(totalNames[i]);
		}
		i += N;
	}

	for(int i = 0; i < winners.size(); i++) {
		cout << winners[i] << endl;
	}


	return 0;
}
