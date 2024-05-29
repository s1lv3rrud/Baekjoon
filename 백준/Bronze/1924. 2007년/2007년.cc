#include <bits/stdc++.h>

using namespace std;

int x, y, day = 0;

int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int main(int argc, char** argv)
{
    cin >> x >> y;

    day += y;
	for (int i = 0; i < x - 1; i++)
    {
		day += days[i];
	}

    switch (day % 7) {
    case 0:
		cout << "SUN";
		break;
	case 1:
		cout << "MON";
		break;
	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;
    }
    
    
    return 0;
}