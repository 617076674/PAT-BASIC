#include<iostream>
#include<cstring>

using namespace std;

bool output[256];
int count = 0, line = 0;;

int main(){
	fill(output, output + 256, false);
	while(true){
		char c = getchar();
		if(c == '\n'){
			line++;
			if(line == 2){
				break;
			}
			continue;
		}
		if(!output[c]){
			printf("%c", c);
			output[c] = true;
			count++;
			if(count >= 96){
				break;
			}
		}
	}
	return 0;
}
