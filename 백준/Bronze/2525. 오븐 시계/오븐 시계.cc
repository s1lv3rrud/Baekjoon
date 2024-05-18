#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    int h, m, a;

    cin >> h >> m >> a;

    m += a;
    if (m >= 60)
    {
		h += m / 60;
		m %= 60;
	}

    if (h >= 24)
    {
        h -= 24;
    }

    cout << h << " " << m << endl;

    return 0;
}