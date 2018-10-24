#include<iostream>
#include<string>

using namespace std;

int main() {
	int count;

	cin >> count;

	string oldName;
	string oldAge;
	string youngName;
	string youngAge;

	string name;
	string age;
	string standardAge1 = "1814/09/06";
	string standardAge2 = "2014/09/06";

	int num = 0;
	int index = 0;
	while (true) {
		cin >> name >> age;
		index++;
		if (age.compare(standardAge1) >= 0 && age.compare(standardAge2) <= 0) {
			num++;
			oldName = name;
			oldAge = age;
			youngName = name;
			youngAge = age;
			break;
		}
		if (index == count) {
			cout << num;
			return 0;
		}
	}


	for (int i = index; i < count; i++) {
		cin >> name >> age;
		if (age.compare(standardAge1) >= 0 && age.compare(standardAge2) <= 0) {
			num++;
			if (age.compare(oldAge) < 0) {
				oldName = name;
				oldAge = age;
			}
			if (age.compare(youngAge) > 0) {
				youngName = name;
				youngAge = age;
			}
		}
	}

	cout << num << " " << oldName << " " << youngName;
}
