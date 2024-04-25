#include <bits/stdc++.h>

using namespace std;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	string str;
	cin >> str;
	double res = 0;

	switch (str[0])
	{
	case 'A':
		res = 4.0;
		break;
	case 'B':
		res = 3.0;
		break;
	case 'C':
		res = 2.0;
		break;
	case 'D':
		res = 1.0;
		break;
	}
	switch (str[1])
	{
	case '+':
		res += 0.3;
		break;
	case '-':
		res -= 0.3;
		break;
	}
	cout << fixed; // 소수부 범위만 설정
	cout.precision(1); // 출력 범위 설정 (정수부 + 소수부)
	cout << res;

    return 0;
}