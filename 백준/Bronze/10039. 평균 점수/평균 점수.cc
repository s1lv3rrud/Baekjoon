#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	int s, avg = 0;
	for (int i = 0; i < 5; i++) {
		cin >> s;
		if(s<40) s = 40;
		avg += s;
	}
	cout << avg / 5;

    return 0;
}