#include<iostream>
#include<vector>
#include<utility>
#include<math.h>
#include<map>

using namespace std;

bool isRedInGreen(int *p, int N, int M, int indexi, int indexj, int TOL);

int main(){
	int M, N, TOL;
	cin >> M >> N >> TOL;
	
	int colors[N][M];
	map<int, int> flags;
	
	int tempColor;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%d", &tempColor);
			colors[i][j] = tempColor;
			if(flags.find(tempColor) != flags.end()){
				flags[tempColor]++;
			}else{
				flags[tempColor] = 1;
			}
		}
	}
	
	vector<pair<int, int> > reds;
	pair<int, int> tempPair;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(isRedInGreen((int *)colors, N, M, i, j, TOL) && flags[colors[i][j]] == 1){
				tempPair.first = i;
				tempPair.second = j;
				reds.push_back(tempPair);
			}
		}
	}
	
	if(reds.size() == 0){
		cout << "Not Exist" << endl;
	}else if(reds.size() > 1){
		cout << "Not Unique" << endl;
	}else{
		int indexi = reds[0].first;
		int indexj = reds[0].second;
		cout << "(" << indexj + 1 << ", " << indexi + 1 << "): " << colors[indexi][indexj] << endl;
	}
}

bool isRedInGreen(int *p, int N, int M, int indexi, int indexj, int TOL){
	int directions[8][2] = {{1, 1}, {1, 0}, {1, -1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, 1}, {0, -1}};
	for(int i = 0; i < 8; i++){
		int newi = indexi + directions[i][0];
		int newj = indexj + directions[i][1];
		if(newi < 0 || newi >= N || newj < 0 || newj >= M){
			continue;
		}
		int preColor = *(p + indexi * M + indexj);
		int newColor = *(p + newi * M + newj);
		if(abs(newColor - preColor) <= TOL){
			return false;
		}
	}
	return true;
}
